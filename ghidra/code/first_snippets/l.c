
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void l(void)

{
  char ae [5];
  uchar ad;
  int af;
  
  builtin_strncpy(ae,"7654",5);
  for (af = 0; ae[af] != '\0'; af = af + 1) {
    ae[af] = ae[af] ^ 0x55;
  }
  printf("Decrypted: %s\n",ae);
  return;
}

