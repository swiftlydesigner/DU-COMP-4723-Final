#include <stdio.h>
#include <string.h>

#define COMMAND_COUNT 3

typedef int (*command_handler_t)(void);

typedef struct
{
    const char *name;
    command_handler_t handler;
} command_t;

/*
Changes made:
- Replaced writable stack buffers with const string command names.
- Removed manual null-padding of command names.
- Replaced NULL handlers with real handler functions.
- Added NULL and empty-string validation.
- Replaced while(true) loop with bounded for-loop.
- Kept unknown-command printf safe by using a fixed format string.
*/

static int handle_help(void)
{
    puts("Available commands: help, version, exit");
    return 0;
}

static int handle_version(void)
{
    puts("System Shell v3.1.4");
    return 0;
}

static int handle_exit(void)
{
    puts("Exiting...");
    return 1;
}

int exec_help_version_exit(const char *command)
{
    int status_indicator;
    int command_tries;

    /*
    Original removed code:

    char *b_local;
    command_t commands[3];

    builtin_strncpy(commands[0].name, "help", 5);
    commands[0].name[5] = '\0';
    commands[0].name[6] = '\0';
    commands[0].name[7] = '\0';
    commands[0].name[8] = '\0';
    commands[0].name[9] = '\0';
    commands[0].name[10] = '\0';
    commands[0].name[0xb] = '\0';
    commands[0].name[0xc] = '\0';
    commands[0].name[0xd] = '\0';
    commands[0].name[0xe] = '\0';
    commands[0].name[0xf] = '\0';
    commands[0].name[0x10] = '\0';
    commands[0].name[0x11] = '\0';
    commands[0].name[0x12] = '\0';
    commands[0].name[0x13] = '\0';
    commands[0].name[0x14] = '\0';
    commands[0].name[0x15] = '\0';
    commands[0].name[0x16] = '\0';
    commands[0].name[0x17] = '\0';
    commands[0].name[0x18] = '\0';
    commands[0].name[0x19] = '\0';
    commands[0].name[0x1a] = '\0';
    commands[0].name[0x1b] = '\0';
    commands[0].name[0x1c] = '\0';
    commands[0].name[0x1d] = '\0';
    commands[0].name[0x1e] = '\0';
    commands[0].name[0x1f] = '\0';
    commands[0].handler = 0x0;

    builtin_strncpy(commands[1].name, "version", 8);
    commands[1].name[8] = '\0';
    commands[1].name[9] = '\0';
    commands[1].name[10] = '\0';
    commands[1].name[0xb] = '\0';
    commands[1].name[0xc] = '\0';
    commands[1].name[0xd] = '\0';
    commands[1].name[0xe] = '\0';
    commands[1].name[0xf] = '\0';
    commands[1].name[0x10] = '\0';
    commands[1].name[0x11] = '\0';
    commands[1].name[0x12] = '\0';
    commands[1].name[0x13] = '\0';
    commands[1].name[0x14] = '\0';
    commands[1].name[0x15] = '\0';
    commands[1].name[0x16] = '\0';
    commands[1].name[0x17] = '\0';
    commands[1].name[0x18] = '\0';
    commands[1].name[0x19] = '\0';
    commands[1].name[0x1a] = '\0';
    commands[1].name[0x1b] = '\0';
    commands[1].name[0x1c] = '\0';
    commands[1].name[0x1d] = '\0';
    commands[1].name[0x1e] = '\0';
    commands[1].name[0x1f] = '\0';
    commands[1].handler = 0x0;

    builtin_strncpy(commands[2].name, "exit", 5);
    commands[2].name[5] = '\0';
    commands[2].name[6] = '\0';
    commands[2].name[7] = '\0';
    commands[2].name[8] = '\0';
    commands[2].name[9] = '\0';
    commands[2].name[10] = '\0';
    commands[2].name[0xb] = '\0';
    commands[2].name[0xc] = '\0';
    commands[2].name[0xd] = '\0';
    commands[2].name[0xe] = '\0';
    commands[2].name[0xf] = '\0';
    commands[2].name[0x10] = '\0';
    commands[2].name[0x11] = '\0';
    commands[2].name[0x12] = '\0';
    commands[2].name[0x13] = '\0';
    commands[2].name[0x14] = '\0';
    commands[2].name[0x15] = '\0';
    commands[2].name[0x16] = '\0';
    commands[2].name[0x17] = '\0';
    commands[2].name[0x18] = '\0';
    commands[2].name[0x19] = '\0';
    commands[2].name[0x1a] = '\0';
    commands[2].name[0x1b] = '\0';
    commands[2].name[0x1c] = '\0';
    commands[2].name[0x1d] = '\0';
    commands[2].name[0x1e] = '\0';
    commands[2].name[0x1f] = '\0';
    commands[2].handler = 0x0;
    */

    /* New safer command table. */
    static const command_t commands[COMMAND_COUNT] = {
        {"help", handle_help},
        {"version", handle_version},
        {"exit", handle_exit}
    };

    /* Added validation before strcmp(). */
    if (command == NULL || command[0] == '\0') {
        puts("Invalid command.");
        return -1;
    }

    /*
    Original removed loop:

    command_tries = 0;
    while (true) {
        if (2 < command_tries) {
            printf("Unknown command: %s\n", command);
            return -1;
        }

        status_indicator = strcmp(command, commands[command_tries].name);

        if (status_indicator == 0) {
            break;
        }

        command_tries = command_tries + 1;
    }
    */

    /* New bounded loop prevents accidental out-of-bounds access. */
    for (command_tries = 0; command_tries < COMMAND_COUNT; command_tries++) {
        status_indicator = strcmp(command, commands[command_tries].name);

        if (status_indicator == 0) {
            /*
            Original handler check kept, but now handlers are real functions:

            if (commands[command_tries].handler != 0x0) {
                status_indicator = (*commands[command_tries].handler)(command);
                return status_indicator;
            }
            return 0;
            */

            if (commands[command_tries].handler == NULL) {
                puts("Command handler missing.");
                return -1;
            }

            return commands[command_tries].handler();
        }
    }

    printf("Unknown command: %s\n", command);

    return -1;
}
