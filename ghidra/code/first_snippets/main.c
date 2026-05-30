
int main(int argc,char **argv)

{
  char *pcVar1;
  char **argv_local;
  int argc_local;
  char n [128];
  
  setvbuf(stdout,(char *)0x0,2,0);
  printf("System Shell v3.1.4\n> ");
  pcVar1 = fgets(n,0x80,stdin);
  if (pcVar1 != (char *)0x0) {
    c(n);
  }
  return (int)(pcVar1 == (char *)0x0);
}

