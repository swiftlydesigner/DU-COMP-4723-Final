
/* DISPLAY WARNING: Type casts are NOT being printed */

int exec_help_version_exit(char *command)

{
  int status_indicator;
  char *b_local;
  command_t commands [3];
  int command_tries;
  
  builtin_strncpy(commands[0].name,"help",5);
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
  builtin_strncpy(commands[1].name,"version",8);
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
  builtin_strncpy(commands[2].name,"exit",5);
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
  command_tries = 0;
  while( true ) {
                    /* There are only 2 tries at the command line
                       until unknown command is returned. */
    if (2 < command_tries) {
      printf("Unknown command: %s\n",command);
      return -1;
    }
                    /* Compare the command from user with an accepable commands.
                       0 if matches, 1 if mismatch. Effectively checks if the
                       user-provided command matches the list of acceptable
                       commands. If the command is valid, the inf while loop
                       will break prior returning -1. */
    status_indicator = strcmp(command,commands[command_tries].name);
                    /* Break loop when a valid command is recognized */
    if (status_indicator == 0) break;
                    /* Increment command_tries to check next command. */
    command_tries = command_tries + 1;
  }
                    /* Validate the command handler exists */
  if (commands[command_tries].handler != 0x0) {
                    /* Return the code from the command_t's handler, passing in the command. */
    status_indicator = (*commands[command_tries].handler)(command);
    return status_indicator;
  }
  return 0;
}

