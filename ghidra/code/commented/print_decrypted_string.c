
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* DISPLAY WARNING: Type casts are NOT being printed */

void print_decrypted_string(void)

{
  char encrypted_string [5];
  uchar dummy;
  int i;
  
                    /* Copy the encrypted string to the character array */
  builtin_strncpy(encrypted_string,"7654",5);
  for (i = 0; encrypted_string[i] != '\0'; i = i + 1) {
                    /* XOR the char value with 85 to (en/de)crypt the string. */
    encrypted_string[i] = encrypted_string[i] ^ 85;
  }
  printf("Decrypted: %s\n",encrypted_string);
  return;
}

