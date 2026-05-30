
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void h(void)

{
  uint uVar1;
  char w [256];
  time_t u;
  int x;
  tm *v;
  
  u = time((time_t *)0x0);
  v = (tm *)localtime(&u);
  if ((v->tm_wday == 0) && (v->tm_hour == 3)) {
    puts("Midnight maintenance mode active");
  }
  uVar1 = getpid();
  snprintf(w,0x100,"/tmp/.hidden_%d",(ulong)uVar1);
  x = open(w,0x41,0x180);
  if (x != -1) {
    write(x,"secret data",0xc);
    close(x);
  }
  return;
}

