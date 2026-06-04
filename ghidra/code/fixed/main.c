#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USER_BUFFER_SIZE 128

int main(int argc, char **argv)
{
    char usr_buffer[USER_BUFFER_SIZE];

    /*
     * Original code kept for reference:
     *
     * char *usr_input;
     * char **none;
     * int none1;
     * char usr_buffer [128];
     *
     * setvbuf(stdout,0,2,0);
     * printf("System Shell v3.1.4\n> ");
     * usr_input = fgets(usr_buffer,128,stdin);
     *
     * if (usr_input != 0) {
     *   parse_command(usr_buffer);
     * }
     *
     * return usr_input == 0;
     */

    /*
     * Removed unused variables:
     * - char **none;
     * - int none1;
     *
     * These appear to be decompiler artifacts or unused local variables.
     * Keeping unused variables can make reverse engineering harder and may hide real logic issues.
     */

    /*
     * Keep stdout unbuffered so the prompt appears immediately.
     * Original behavior preserved, but constants are made clearer.
     */
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("System Shell v3.1.4\n> ");

    /*
     * Safely read at most USER_BUFFER_SIZE - 1 bytes.
     * fgets() null-terminates the buffer when successful.
     */
    if (fgets(usr_buffer, sizeof(usr_buffer), stdin) == NULL) {
        /*
         * Return nonzero on input failure or EOF.
         * This is clearer than returning the result of a pointer comparison.
         */
        return EXIT_FAILURE;
    }

    /*
     * Remove trailing newline if present.
     * This prevents parse_command() from receiving commands with '\n'
     * unless that behavior is intentionally required.
     */
    usr_buffer[strcspn(usr_buffer, "\n")] = '\0';

    /*
     * Reject empty input before passing it to parse_command().
     * This reduces unnecessary parser handling and avoids edge-case behavior.
     */
    if (usr_buffer[0] == '\0') {
        fprintf(stderr, "No command entered.\n");
        return EXIT_FAILURE;
    }

    /*
     * Optional hardening:
     * Detect overly long input that may have been truncated by fgets().
     * If there is no newline and the buffer is full, extra input may remain in stdin.
     */
    if (strlen(usr_buffer) == sizeof(usr_buffer) - 1) {
        fprintf(stderr, "Input too long.\n");

        /*
         * Clear remaining characters from stdin to avoid command smuggling
         * into future reads.
         */
        int leftover_char;
        while ((leftover_char = getchar()) != '\n' && leftover_char != EOF) {
            /*
             * Discard extra input.
             */
        }

        return EXIT_FAILURE;
    }

    /*
     * Call command parser only after basic input validation.
     */
    parse_command(usr_buffer);

    return EXIT_SUCCESS;
}
