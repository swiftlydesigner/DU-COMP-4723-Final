/*Security note: time-based conditions can sometimes 
be used as hidden triggers in reverse-engineered binaries, 
especially when paired with secret/debug functionality. 
This one only prints a maintenance message, 
so it appears low risk by itself. However, 
if another function uses a similar time % value == 0 condition to unlock behavior, 
bypass checks, or reveal data, that would be worth investigating closely.*/

#include <stdio.h>
#include <time.h>

#define SECONDS_PER_HOUR 3600
#define TOP_OF_HOUR_WINDOW_SECONDS 60

void print_maintenance_top_of_hour(void)
{
    time_t current_time;
    time_t seconds_after_hour;

    /*
     * Original strict check kept for reference:
     *
     * current_time = time(0x0);
     *
     * if (current_time % 3600 == 0) {
     *   puts("System maintenance scheduled");
     * }
     */

    current_time = time(NULL);

    if (current_time == (time_t)-1) {
        fprintf(stderr, "Unable to read system time.\n");
        return;
    }

    seconds_after_hour = current_time % SECONDS_PER_HOUR;

    /*
     * Safer and more useful behavior:
     * Print the maintenance message during the first 60 seconds of each hour.
     */
    if (seconds_after_hour < TOP_OF_HOUR_WINDOW_SECONDS) {
        puts("System maintenance scheduled");
    }

    return;
}
