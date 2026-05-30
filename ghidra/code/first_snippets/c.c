
void c(char *d)

{
  int iVar1;
  char *pcVar2;
  char *d_local;
  int p;
  char *o;
  
  pcVar2 = strtok(d," \n");
  if (pcVar2 != (char *)0x0) {
    iVar1 = strcmp(pcVar2,"run");
    if (iVar1 == 0) {
      pcVar2 = strtok((char *)0x0," \n");
      if (pcVar2 != (char *)0x0) {
        iVar1 = atoi(pcVar2);
        pcVar2 = strtok((char *)0x0," \n");
        if (pcVar2 != (char *)0x0) {
          e(iVar1,pcVar2);
        }
      }
    }
    else {
      iVar1 = strcmp(pcVar2,"cmd");
      if (iVar1 == 0) {
        pcVar2 = strtok((char *)0x0,"\n");
        if (pcVar2 != (char *)0x0) {
          a(pcVar2);
        }
      }
      else {
        iVar1 = strcmp(pcVar2,"secret");
        if (iVar1 == 0) {
          h();
        }
      }
    }
  }
  return;
}

