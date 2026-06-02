
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* DISPLAY WARNING: Type casts are NOT being printed */

void read_flag_from_file(void)

{
  FILE *in_file;
  char flag_buffer [64];
  FILE *dummy;
  
  in_file = fopen("/flag.txt","r");
                    /* If file opened, read and print the flag,
                       then close the opened file. */
  if (in_file != 0x0) {
    fgets(flag_buffer,64,in_file);
    printf("FLAG: %s",flag_buffer);
    fclose(in_file);
  }
  return;
}

