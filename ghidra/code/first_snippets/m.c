
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void m(void)

{
  FILE *__stream;
  char ag [64];
  FILE *ah;
  
  __stream = fopen("/flag.txt","r");
  if (__stream != (FILE *)0x0) {
    fgets(ag,0x40,__stream);
    printf("FLAG: %s",ag);
    fclose(__stream);
  }
  return;
}

