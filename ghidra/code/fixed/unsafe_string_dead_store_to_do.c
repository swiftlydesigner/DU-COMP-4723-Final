
/* DISPLAY WARNING: Type casts are NOT being printed */

void unsafe_string_dead_store(int func,char *string)

{
  char *dummy2;
  int dummy;
  char target [64];
  int dummy3;
  
  if (func == 1) {
                    /* Insecurely copy input string (from user)
                       to the local target buffer. */
    strcpy(target,string);
  }
  else if (func == 2) {
                    /* Copy 64 bytes from string to target,
                       possibly unterminated string (effectively char array)
                        */
    strncpy(target,string,64);
  }
  else if (func == 3) {
                    /* Securely copy from string to target */
    snprintf(target,64,"%s",string);
  }
  puts("Operation completed successfully");
  return;
}

