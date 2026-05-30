
int a(char *b)

{
  int iVar1;
  char *b_local;
  command_t s [3];
  int t;
  
  builtin_strncpy(s[0].name,"help",5);
  s[0].name[5] = '\0';
  s[0].name[6] = '\0';
  s[0].name[7] = '\0';
  s[0].name[8] = '\0';
  s[0].name[9] = '\0';
  s[0].name[10] = '\0';
  s[0].name[0xb] = '\0';
  s[0].name[0xc] = '\0';
  s[0].name[0xd] = '\0';
  s[0].name[0xe] = '\0';
  s[0].name[0xf] = '\0';
  s[0].name[0x10] = '\0';
  s[0].name[0x11] = '\0';
  s[0].name[0x12] = '\0';
  s[0].name[0x13] = '\0';
  s[0].name[0x14] = '\0';
  s[0].name[0x15] = '\0';
  s[0].name[0x16] = '\0';
  s[0].name[0x17] = '\0';
  s[0].name[0x18] = '\0';
  s[0].name[0x19] = '\0';
  s[0].name[0x1a] = '\0';
  s[0].name[0x1b] = '\0';
  s[0].name[0x1c] = '\0';
  s[0].name[0x1d] = '\0';
  s[0].name[0x1e] = '\0';
  s[0].name[0x1f] = '\0';
  s[0].handler = (_func_int_char_ptr *)0x0;
  builtin_strncpy(s[1].name,"version",8);
  s[1].name[8] = '\0';
  s[1].name[9] = '\0';
  s[1].name[10] = '\0';
  s[1].name[0xb] = '\0';
  s[1].name[0xc] = '\0';
  s[1].name[0xd] = '\0';
  s[1].name[0xe] = '\0';
  s[1].name[0xf] = '\0';
  s[1].name[0x10] = '\0';
  s[1].name[0x11] = '\0';
  s[1].name[0x12] = '\0';
  s[1].name[0x13] = '\0';
  s[1].name[0x14] = '\0';
  s[1].name[0x15] = '\0';
  s[1].name[0x16] = '\0';
  s[1].name[0x17] = '\0';
  s[1].name[0x18] = '\0';
  s[1].name[0x19] = '\0';
  s[1].name[0x1a] = '\0';
  s[1].name[0x1b] = '\0';
  s[1].name[0x1c] = '\0';
  s[1].name[0x1d] = '\0';
  s[1].name[0x1e] = '\0';
  s[1].name[0x1f] = '\0';
  s[1].handler = (_func_int_char_ptr *)0x0;
  builtin_strncpy(s[2].name,"exit",5);
  s[2].name[5] = '\0';
  s[2].name[6] = '\0';
  s[2].name[7] = '\0';
  s[2].name[8] = '\0';
  s[2].name[9] = '\0';
  s[2].name[10] = '\0';
  s[2].name[0xb] = '\0';
  s[2].name[0xc] = '\0';
  s[2].name[0xd] = '\0';
  s[2].name[0xe] = '\0';
  s[2].name[0xf] = '\0';
  s[2].name[0x10] = '\0';
  s[2].name[0x11] = '\0';
  s[2].name[0x12] = '\0';
  s[2].name[0x13] = '\0';
  s[2].name[0x14] = '\0';
  s[2].name[0x15] = '\0';
  s[2].name[0x16] = '\0';
  s[2].name[0x17] = '\0';
  s[2].name[0x18] = '\0';
  s[2].name[0x19] = '\0';
  s[2].name[0x1a] = '\0';
  s[2].name[0x1b] = '\0';
  s[2].name[0x1c] = '\0';
  s[2].name[0x1d] = '\0';
  s[2].name[0x1e] = '\0';
  s[2].name[0x1f] = '\0';
  s[2].handler = (_func_int_char_ptr *)0x0;
  t = 0;
  while( true ) {
    if (2 < (uint)t) {
      printf("Unknown command: %s\n",b);
      return -1;
    }
    iVar1 = strcmp(b,s[t].name);
    if (iVar1 == 0) break;
    t = t + 1;
  }
  if (s[t].handler != (_func_int_char_ptr *)0x0) {
    iVar1 = (*s[t].handler)(b);
    return iVar1;
  }
  return 0;
}

