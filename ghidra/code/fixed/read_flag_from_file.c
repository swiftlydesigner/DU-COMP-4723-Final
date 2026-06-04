/*
Key Findings Summary:
This function directly opens `/flag.txt`, reads up to 63 bytes into a stack buffer, 
and prints the contents with `printf("FLAG: %s", flag_buffer)`. That is a clear sensitive-data leak. 
The hardcoded `/flag.txt` path is also suspicious because it looks like a CTF flag, secret file, token, 
or protected credential path. There is no visible setuid call in this snippet, 
but if this function is reachable through the earlier `secret` command or privilege-escalation path, 
it becomes much more serious. The main issue is not memory safety, since `fgets()` is bounded, 
but authorization and disclosure: there is no access check before reading and printing the secret.

Recommended fix: do not print the flag or secret in production. Restrict access to this function, 
remove hidden command paths that call it, handle file errors clearly, close the file on all paths, 
and wipe the buffer after use.
*/

#include <stdio.h>
#include <string.h>

#define FLAG_BUFFER_SIZE 64

void read_flag_from_file(void)
{
    FILE *in_file;
    char flag_buffer[FLAG_BUFFER_SIZE];

    /*
     * Original code kept for reference:
     *
     * void read_flag_from_file(void)
     * {
     *   FILE *in_file;
     *   char flag_buffer [64];
     *   FILE *dummy;
     *
     *   in_file = fopen("/flag.txt","r");
     *
     *   if (in_file != 0x0) {
     *     fgets(flag_buffer,64,in_file);
     *     printf("FLAG: %s",flag_buffer);
     *     fclose(in_file);
     *   }
     *
     *   return;
     * }
     */

    /*
     * Removed unused variable:
     * - FILE *dummy;
     *
     * This is likely a decompiler artifact or dead variable.
     */

    /*
     * Original risky behavior:
     * in_file = fopen("/flag.txt", "r");
     * printf("FLAG: %s", flag_buffer);
     *
     * This directly reads and prints a sensitive file.
     * In production, secrets should not be printed to stdout.
     */

    in_file = fopen("/flag.txt", "r");

    if (in_file == NULL) {
        fprintf(stderr, "Unable to open restricted file.\n");
        return;
    }

    if (fgets(flag_buffer, sizeof(flag_buffer), in_file) == NULL) {
        fprintf(stderr, "Unable to read restricted file.\n");
        fclose(in_file);
        return;
    }

    fclose(in_file);

    /*
     * Remove trailing newline if present.
     */
    flag_buffer[strcspn(flag_buffer, "\n")] = '\0';

    /*
     * Security hardening:
     * Do not print the secret value.
     *
     * Original behavior:
     * printf("FLAG: %s", flag_buffer);
     */

#ifdef DEBUG
    printf("FLAG: %s\n", flag_buffer);
#else
    printf("Restricted file was read successfully.\n");
#endif

    /*
     * Clear sensitive data from stack memory after use.
     */
    volatile char *wipe_pointer = flag_buffer;

    for (size_t index = 0; index < sizeof(flag_buffer); index++) {
        wipe_pointer[index] = '\0';
    }

    return;
}
