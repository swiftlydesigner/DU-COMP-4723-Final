
void e(int f,char *g)

{
  char *g_local;
  int f_local;
  char q [64];
  int r;
  
  if (f == 1) {
    strcpy(q,g);
  }
  else if (f == 2) {
    strncpy(q,g,0x40);
  }
  else if (f == 3) {
    snprintf(q,0x40,"%s",g);
  }
  puts("Operation completed successfully");
  return;
}

