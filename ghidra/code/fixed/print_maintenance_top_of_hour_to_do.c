
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* DISPLAY WARNING: Type casts are NOT being printed */

void print_maintenance_top_of_hour(void)

{
  time_t current_time;
  time_t dummy;
  
  current_time = time(0x0);
                    /* If the current_time is an hour, on the dot (3600sec = 1hr),
                       print system maintenance is scheduled */
  if (current_time % 3600 == 0) {
    puts("System maintenance scheduled");
  }
  return;
}

