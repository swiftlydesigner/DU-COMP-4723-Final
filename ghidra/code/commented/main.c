
/* DISPLAY WARNING: Type casts are NOT being printed */

int main(int argc,char **argv)

{
  char *usr_input;
  char **none;
  int none1;
  char usr_buffer [128];
  
  setvbuf(stdout,0,2,0);
  printf("System Shell v3.1.4\n> ");
  usr_input = fgets(usr_buffer,128,stdin);
                    /* Call func `parse_command` when user input is valid (non-null) */
  if (usr_input != 0) {
    parse_command(usr_buffer);
  }
                    /* Return exit code 0 when user input is valid. */
  return usr_input == 0;
}

