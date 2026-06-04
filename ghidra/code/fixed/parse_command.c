/*
Key Findings:
The biggest issue is the `secret` command. Anyone can type `secret` and trigger `write_secret_file()` 
with no login, permission check, or authorization, which makes it look like a hidden debug command or 
auth bypass.

The `cmd` path also needs review because it passes user input into `exec_help_version_exit()`. 
If that function runs shell commands or uses `system()`, `exec*()`, or `popen()`, 
it could lead to command injection.

The `run` path is risky because it uses `atoi()` and sends user-controlled input into 
`unsafe_string_dead_store()`. Bad input can be misread, and the copy function may be unsafe depending 
on the selected mode.

No setuid flow or key leak is shown in this snippet, but `write_secret_file()`,
`exec_help_version_exit()`, and `unsafe_string_dead_store()` should be checked closely.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define MAX_COMMAND_LENGTH 128
#define MAX_ARGUMENT_LENGTH 64

/*
 * Expected external functions.
 * Keep these declarations only if they are not already declared in a header.
 */
void unsafe_string_dead_store(int mode, const char *input);
void exec_help_version_exit(const char *command);
void write_secret_file(void);

static int parse_safe_int(const char *input, int *result)
{
    char *end_pointer;
    long parsed_value;

    if (input == NULL || result == NULL) {
        return 0;
    }

    errno = 0;
    parsed_value = strtol(input, &end_pointer, 10);

    if (errno != 0 || end_pointer == input || *end_pointer != '\0') {
        return 0;
    }

    if (parsed_value < INT_MIN || parsed_value > INT_MAX) {
        return 0;
    }

    *result = (int)parsed_value;
    return 1;
}

static int is_valid_run_mode(int mode)
{
    /*
     * Original behavior suggests:
     * 1 = strcpy path
     * 2 = strncpy path
     * 3 = snprintf path
     *
     * Only allow known modes.
     */
    if (mode == 1 || mode == 2 || mode == 3) {
        return 1;
    }

    return 0;
}

void parse_command(char *d)
{
    char *token;
    char *argument_one;
    char *argument_two;
    char *save_pointer;
    int run_mode;

    /*
     * Original code kept for reference:
     *
     * void parse_command(char *d)
     * {
     *   int strcmp_val;
     *   char *token;
     *   char *dummy;
     *   int p;
     *   char *o;
     *
     *   token = strtok(d," \n");
     *
     *   if (token != 0x0) {
     *     strcmp_val = strcmp(token,"run");
     *
     *     if (strcmp_val == 0) {
     *       token = strtok(0x0," \n");
     *
     *       if (token != 0x0) {
     *         strcmp_val = atoi(token);
     *         token = strtok(0x0," \n");
     *
     *         if (token != 0x0) {
     *           unsafe_string_dead_store(strcmp_val,token);
     *         }
     *       }
     *     }
     *     else {
     *       strcmp_val = strcmp(token,"cmd");
     *
     *       if (strcmp_val == 0) {
     *         token = strtok(0x0,"\n");
     *
     *         if (token != 0x0) {
     *           exec_help_version_exit(token);
     *         }
     *       }
     *       else {
     *         strcmp_val = strcmp(token,"secret");
     *
     *         if (strcmp_val == 0) {
     *           write_secret_file();
     *         }
     *       }
     *     }
     *   }
     *
     *   return;
     * }
     */

    /*
     * Removed unused variables:
     * - char *dummy;
     * - int p;
     * - char *o;
     *
     * These are likely decompiler artifacts or dead variables.
     */

    if (d == NULL) {
        fprintf(stderr, "Invalid command input.\n");
        return;
    }

    /*
     * Use strtok_r instead of strtok.
     * strtok uses internal global state and is not thread-safe.
     */
    token = strtok_r(d, " \n", &save_pointer);

    if (token == NULL) {
        fprintf(stderr, "Empty command.\n");
        return;
    }

    if (strcmp(token, "run") == 0) {
        argument_one = strtok_r(NULL, " \n", &save_pointer);
        argument_two = strtok_r(NULL, " \n", &save_pointer);

        if (argument_one == NULL || argument_two == NULL) {
            fprintf(stderr, "Usage: run <mode> <input>\n");
            return;
        }

        /*
         * Original code used atoi(), which is unsafe for validation because:
         * - atoi("abc") returns 0
         * - atoi("123abc") returns 123
         * - overflow behavior is not safely reported
         */
        if (!parse_safe_int(argument_one, &run_mode)) {
            fprintf(stderr, "Invalid run mode.\n");
            return;
        }

        if (!is_valid_run_mode(run_mode)) {
            fprintf(stderr, "Unsupported run mode.\n");
            return;
        }

        /*
         * Basic length check before passing user-controlled data forward.
         * This is important because the downstream function name suggests unsafe string handling.
         */
        if (strlen(argument_two) >= MAX_ARGUMENT_LENGTH) {
            fprintf(stderr, "Run input is too long.\n");
            return;
        }

        /*
         * Security note:
         * This still calls the original downstream function, but only after validation.
         * The safer long-term fix is to replace unsafe_string_dead_store() itself.
         */
        unsafe_string_dead_store(run_mode, argument_two);
        return;
    }

    if (strcmp(token, "cmd") == 0) {
        argument_one = strtok_r(NULL, "\n", &save_pointer);

        if (argument_one == NULL) {
            fprintf(stderr, "Usage: cmd <command>\n");
            return;
        }

        /*
         * Security hardening:
         * The original code passed everything after "cmd" directly to exec_help_version_exit().
         * That function name suggests it may dispatch commands such as help/version/exit.
         * Keep this restricted unless command execution is truly intended.
         */
        while (*argument_one == ' ') {
            argument_one++;
        }

        if (strcmp(argument_one, "help") != 0 &&
            strcmp(argument_one, "version") != 0 &&
            strcmp(argument_one, "exit") != 0) {
            fprintf(stderr, "Unsupported cmd argument.\n");
            return;
        }

        exec_help_version_exit(argument_one);
        return;
    }

    if (strcmp(token, "secret") == 0) {
        /*
         * Original code allowed anyone who typed "secret" to call write_secret_file().
         *
         * This is a likely auth bypass or hidden/debug command.
         * A protected operation should require authentication, authorization,
         * or be removed entirely in production builds.
         *
         * Original behavior:
         * write_secret_file();
         */

        fprintf(stderr, "The secret command is disabled without authorization.\n");

        /*
         * Safer production behavior:
         * Do not call write_secret_file() from unauthenticated user input.
         */
        return;
    }

    fprintf(stderr, "Unknown command.\n");
}
