/*
Key Findings Summary:
This function is vulnerable because mode 1 uses strcpy() to copy user-controlled input
into a 64-byte stack buffer. That can cause a classic stack buffer overflow if the input
is longer than the buffer. Mode 2 uses strncpy(target, string, 64), which is safer than strcpy() 
in length, but it can leave the destination without a null terminator if the input is 64 bytes or longer. 
Mode 3 with snprintf() is the safest of the original paths.

There is no direct auth bypass, setuid call, debug secret, or key leak in this snippet. 
The main issue is memory safety. Since this function is reachable from the earlier run command, 
a user could likely trigger the unsafe copy path by entering mode 1. The safest fix is to remove 
the strcpy() and risky strncpy() paths and use one bounded copy method, such as snprintf(), 
while validating input length before copying.
*/

#include <stdio.h>
#include <string.h>

#define TARGET_BUFFER_SIZE 64

void unsafe_string_dead_store(int func, const char *string)
{
    char target[TARGET_BUFFER_SIZE];

    /*
     * Original code kept for reference:
     *
     * void unsafe_string_dead_store(int func,char *string)
     * {
     *   char *dummy2;
     *   int dummy;
     *   char target [64];
     *   int dummy3;
     *
     *   if (func == 1) {
     *     strcpy(target,string);
     *   }
     *   else if (func == 2) {
     *     strncpy(target,string,64);
     *   }
     *   else if (func == 3) {
     *     snprintf(target,64,"%s",string);
     *   }
     *
     *   puts("Operation completed successfully");
     *   return;
     * }
     */

    /*
     * Removed unused variables:
     * - char *dummy2;
     * - int dummy;
     * - int dummy3;
     *
     * These appear to be decompiler artifacts or dead local variables.
     */

    if (string == NULL) {
        fprintf(stderr, "Invalid input string.\n");
        return;
    }

    /*
     * Original dangerous behavior:
     *
     * if (func == 1) {
     *     strcpy(target, string);
     * }
     *
     * strcpy() does not know the size of target.
     * If string is longer than 63 characters, this can overflow target.
     */

    /*
     * Original risky behavior:
     *
     * else if (func == 2) {
     *     strncpy(target, string, 64);
     * }
     *
     * strncpy() does not guarantee null termination when the source
     * is equal to or longer than the destination size.
     */

    /*
     * Original safer behavior:
     *
     * else if (func == 3) {
     *     snprintf(target, 64, "%s", string);
     * }
     *
     * snprintf() is the best option of the original three because it respects
     * the destination size and null-terminates when size is greater than zero.
     */

    if (func != 1 && func != 2 && func != 3) {
        fprintf(stderr, "Unsupported copy mode.\n");
        return;
    }

    /*
     * Hardened behavior:
     * Regardless of the selected mode, use snprintf() for bounded copying.
     * This preserves the general intent while removing the unsafe branches.
     */
    if (snprintf(target, sizeof(target), "%s", string) >= (int)sizeof(target)) {
        fprintf(stderr, "Input was too long and has been safely truncated.\n");
        return;
    }

    /*
     * The original function does not use target after copying into it.
     * That is why the function name "dead_store" makes sense:
     * data is copied into target, but target is never actually used.
     */
    puts("Operation completed successfully");

    return;
}
