/*
Key Findings Summary:
This function does not read all running processes on the computer. It reads `/proc/self/maps`, 
which shows the current process memory map. That can expose loaded libraries, memory regions, 
stack/heap locations, and address layout details. Printing this directly is a debug-information 
leak and could help someone bypass ASLR or understand the binary’s runtime layout. 
There is no direct auth bypass, setuid call, or key leak in this snippet, 
but it should not be reachable in production unless it is protected and intentionally compiled 
under a debug mode. The safest fix is to disable this output by default, only allow it in controlled 
debug builds, use `O_RDONLY`, handle read/open errors, and avoid naming a variable `read` because 
it conflicts with the system call name.
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAPS_BUFFER_SIZE 1024

void read_running_processes_on_comp(void)
{
    int fd;
    ssize_t bytes_read;
    char line[MAPS_BUFFER_SIZE];

    /*
     * Original code kept for reference:
     *
     * void read_running_processes_on_comp(void)
     * {
     *   int fd;
     *   ssize_t read;
     *   char line [1024];
     *   ssize_t dummy2;
     *   int dummy;
     *
     *   fd = open("/proc/self/maps",0);
     *
     *   if (fd != -1) {
     *     while (read = ::read(fd,line,1023), 0 < read) {
     *       line[read] = '\0';
     *       printf("%s",line);
     *     }
     *     close(fd);
     *   }
     *
     *   return;
     * }
     */

    /*
     * Removed unused variables:
     * - ssize_t dummy2;
     * - int dummy;
     *
     * These are likely decompiler artifacts or dead variables.
     */

    /*
     * Renamed variable:
     * - ssize_t read;
     *
     * Using "read" as a variable name can be confusing because read()
     * is also the system call being used.
     */

    /*
     * Original behavior:
     * fd = open("/proc/self/maps", 0);
     *
     * Safer replacement:
     * Use O_RDONLY instead of raw 0 for readability.
     */
    fd = open("/proc/self/maps", O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Unable to open process memory map: %s\n", strerror(errno));
        return;
    }

    /*
     * Security note:
     * /proc/self/maps can reveal memory layout, loaded libraries,
     * stack/heap locations, and shared object paths.
     *
     * Printing this directly can weaken ASLR and help exploit development.
     * In production, this should be disabled or guarded behind a safe debug build.
     */

#ifdef DEBUG
    while ((bytes_read = read(fd, line, sizeof(line) - 1)) > 0) {
        line[bytes_read] = '\0';
        printf("%s", line);
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading process memory map: %s\n", strerror(errno));
    }
#else
    printf("Process map inspection is disabled.\n");
#endif

    close(fd);
    return;
}
