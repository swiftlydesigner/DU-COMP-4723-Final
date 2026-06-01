
/* Formally c. Now expected to be a parse_command function. */

/* DISPLAY WARNING: Type casts are NOT being printed */

void parse_command(char *d)

{
  int strcmp_val;
  char *token;
  char *dummy;
  int p;
  char *o;
  
                    /* Formally c. Now expected to be a parse_command function. */
  token = strtok(d," \n");
                    /* Check if token exists */
  if (token != 0x0) {
                    /* Check if token is "run" */
    strcmp_val = strcmp(token,"run");
                    /* If token is run... */
    if (strcmp_val == 0) {
                    /* Get the next token up to ` \n` */
      token = strtok(0x0," \n");
                    /* Ensure `token` exists */
      if (token != 0x0) {
                    /* Attempt to convert `token` into an int. */
        strcmp_val = atoi(token);
                    /* Get the next token up to ` \n`
                        */
        token = strtok(0x0," \n");
                    /* Ensure the token after int exists */
        if (token != 0x0) {
                    /* Call function e with arguments int and the third token. */
          e(strcmp_val,token);
        }
      }
    }
    else {
                    /* token is not `run`
                       check if token token is cmd */
      strcmp_val = strcmp(token,"cmd");
                    /* If token is cmd */
      if (strcmp_val == 0) {
                    /* get the next token */
        token = strtok(0x0,"\n");
                    /* Ensure token is non-null */
        if (token != 0x0) {
                    /* Pass the 2nd token value, X from (cmd X),
                       to the function a. */
          exec_help_version_exit(token);
        }
      }
      else {
                    /* `token` is not 'run' nor 'cmd'.
                       Check if token is 'secret' */
        strcmp_val = strcmp(token,"secret");
                    /* If `token` is 'secret', call func h. */
        if (strcmp_val == 0) {
          write_secret_file();
        }
      }
    }
  }
  return;
}

