/*
Key Findings Summary:
This function is suspicious because it creates a hidden file in `/tmp` named `.hidden_<pid>` 
and writes `"secret data"` into it. Since the earlier `secret` command calls this function 
without authentication, this looks like a hidden/debug secret-writing path. The `/tmp` 
location is risky because it is shared and writable, and the filename is predictable from 
the process ID, which can create race-condition or symlink issues. The original `open(file_path, 65, 384)` 
likely means `O_WRONLY | O_CREAT` with permissions `0600`, but it does not use safer flags like `O_EXCL` 
or `O_NOFOLLOW`. There is no direct setuid call here, but this becomes more serious if combined with 
the earlier privilege-escalation function. The maintenance message is also inconsistent: 
it says “Midnight” but checks for Sunday at 03:00. Recommended fix: remove unauthenticated access 
to this function, avoid writing secrets to `/tmp`, use safer file creation flags, check all errors, 
and avoid printing hidden maintenance/debug messages in production.
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

#define SECRET_PATH_SIZE 256
#define SECRET_FILE_MODE 0600

void write_secret_file(void)
{
    pid_t pid;
    char file_path[SECRET_PATH_SIZE];
    time_t time_obj;
    struct tm local_time_obj;
    int fd;
    int path_result;

    /*
     * Original code kept for reference:
     *
     * void write_secret_file(void)
     * {
     *   uint pid;
     *   char file_path [256];
     *   time_t time_obj;
     *   int fd;
     *   tm *local_time_obj;
     *
     *   time_obj = time(0x0);
     *   local_time_obj = localtime(&time_obj);
     *
     *   if ((local_time_obj->tm_wday == 0) && (local_time_obj->tm_hour == 3)) {
     *     puts("Midnight maintenance mode active");
     *   }
     *
     *   pid = getpid();
     *
     *   snprintf(file_path,256,"/tmp/.hidden_%d",pid);
     *   fd = open(file_path,65,384);
     *
     *   if (fd != -1) {
     *     write(fd,"secret data",12);
     *     close(fd);
     *   }
     *
     *   return;
     * }
     */

    /*
     * Original suspicious behavior:
     * - Creates a hidden file in /tmp named .hidden_<pid>
     * - Writes "secret data" into it
     * - Is reachable from the earlier "secret" command
     *
     * This looks like a hidden/debug secret-writing path.
     */

    time_obj = time(NULL);

    if (time_obj == (time_t)-1) {
        fprintf(stderr, "Unable to read system time.\n");
        return;
    }

    /*
     * Use localtime_r instead of localtime.
     * localtime uses shared static storage and is not thread-safe.
     */
    if (localtime_r(&time_obj, &local_time_obj) == NULL) {
        fprintf(stderr, "Unable to convert system time.\n");
        return;
    }

    /*
     * Original message kept for reference:
     *
     * if ((local_time_obj->tm_wday == 0) && (local_time_obj->tm_hour == 3)) {
     *     puts("Midnight maintenance mode active");
     * }
     *
     * Logic note:
     * tm_hour == 3 means 3 AM, not midnight.
     * If this is meant to be midnight, tm_hour should be 0.
     */
#ifdef DEBUG
    if ((local_time_obj.tm_wday == 0) && (local_time_obj.tm_hour == 3)) {
        puts("Sunday 03:00 maintenance mode active");
    }
#endif

    pid = getpid();

    path_result = snprintf(file_path, sizeof(file_path), "/tmp/.hidden_%ld", (long)pid);

    if (path_result < 0 || path_result >= (int)sizeof(file_path)) {
        fprintf(stderr, "Secret file path was truncated.\n");
        return;
    }

    /*
     * Original open flags:
     *
     * fd = open(file_path, 65, 384);
     *
     * 65 likely means O_WRONLY | O_CREAT.
     * 384 is octal 0600.
     *
     * Security issue:
     * Opening predictable files in /tmp can be dangerous because /tmp is shared.
     * A local user may be able to race, pre-create, or symlink the path.
     *
     * Hardened behavior:
     * - O_CREAT: create the file if missing
     * - O_EXCL: fail if it already exists
     * - O_NOFOLLOW: do not follow symlinks
     * - O_WRONLY: write-only
     */
    fd = open(file_path, O_WRONLY | O_CREAT | O_EXCL | O_NOFOLLOW, SECRET_FILE_MODE);

    if (fd == -1) {
        fprintf(stderr, "Unable to safely create secret file.\n");
        return;
    }

    /*
     * Original behavior:
     *
     * write(fd, "secret data", 12);
     *
     * Security hardening:
     * Check the write result instead of assuming it succeeded.
     */
    if (write(fd, "secret data", strlen("secret data")) == -1) {
        fprintf(stderr, "Unable to write secret data.\n");
        close(fd);
        unlink(file_path);
        return;
    }

    close(fd);
    return;
}
