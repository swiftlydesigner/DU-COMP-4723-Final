
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void k(void)

{
  int __fd;
  ssize_t sVar1;
  char ab [1024];
  ssize_t ac;
  int aa;
  
  __fd = open("/proc/self/maps",0);
  if (__fd != -1) {
    while (sVar1 = read(__fd,ab,0x3ff), 0 < sVar1) {
      ab[sVar1] = '\0';
      printf("%s",ab);
    }
    close(__fd);
  }
  return;
}

