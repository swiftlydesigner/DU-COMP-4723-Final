
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void i(void)

{
  time_t tVar1;
  time_t y;
  
  tVar1 = time((time_t *)0x0);
  if (tVar1 % 0xe10 == 0) {
    puts("System maintenance scheduled");
  }
  return;
}

