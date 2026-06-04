#include <stdio.h>
#include <string.h>

#define XOR_KEY 0x55
#define ENCRYPTED_STRING_SIZE 5

void print_decrypted_string(void)
{
    char encrypted_string[ENCRYPTED_STRING_SIZE];
    size_t index;

    /*
     * Original code kept for reference:
     *
     * void print_decrypted_string(void)
     * {
     *   char encrypted_string [5];
     *   uchar dummy;
     *   int i;
     *
     *   builtin_strncpy(encrypted_string,"7654",5);
     *   for (i = 0; encrypted_string[i] != '\0'; i = i + 1) {
     *     encrypted_string[i] = encrypted_string[i] ^ 85;
     *   }
     *   printf("Decrypted: %s\n",encrypted_string);
     *   return;
     * }
     */

    /*
     * Removed unused variable:
     * - uchar dummy;
     *
     * This is likely a decompiler artifact or dead local variable.
     */

    /*
     * Original code:
     * builtin_strncpy(encrypted_string,"7654",5);
     *
     * Safer replacement:
     * Use memcpy because the source is a fixed-size known byte sequence.
     * The final byte is explicitly preserved as '\0'.
     */
    memcpy(encrypted_string, "7654", ENCRYPTED_STRING_SIZE);

    /*
     * Decrypt only the actual encrypted bytes.
     * Do not XOR the null terminator.
     */
    for (index = 0; index < ENCRYPTED_STRING_SIZE - 1; index++) {
        encrypted_string[index] = encrypted_string[index] ^ XOR_KEY;
    }

    /*
     * Security hardening:
     * The original code printed the decrypted value directly.
     *
     * Original code:
     * printf("Decrypted: %s\n", encrypted_string);
     *
     * Printing decrypted secrets is a likely debug-output leak.
     * In production, avoid printing secrets to stdout, logs, crash reports,
     * or terminal history.
     */

#ifdef DEBUG
    printf("Decrypted: %s\n", encrypted_string);
#else
    printf("Decryption completed.\n");
#endif

    /*
     * Optional cleanup:
     * Clear decrypted data from stack memory after use.
     * volatile prevents the compiler from easily optimizing the wipe away.
     */
    volatile char *wipe_pointer = encrypted_string;

    for (index = 0; index < ENCRYPTED_STRING_SIZE; index++) {
        wipe_pointer[index] = '\0';
    }

    return;
}
