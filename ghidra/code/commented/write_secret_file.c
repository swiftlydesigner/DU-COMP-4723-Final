
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Write to a file in /tmp/  */

/* DISPLAY WARNING: Type casts are NOT being printed */

void write_secret_file(void)

{
  uint pid;
  char file_path [256];
  time_t time_obj;
  int fd;
  tm *local_time_obj;
  
  time_obj = time(0x0);
  local_time_obj = localtime(&time_obj);
                    /* Print to the screen that maintenance mode is active
                       when it is 03:00 Sunday. */
  if ((local_time_obj->tm_wday == 0) && (local_time_obj->tm_hour == 3)) {
    puts("Midnight maintenance mode active");
  }
  pid = getpid();
                    /* Create a file under the tmp dir with name '.hidden{PID}'
                       where PID is the process id. */
  snprintf(file_path,256,"/tmp/.hidden_%d",pid);
  fd = open(file_path,65,384);
                    /* Check the file was opened. */
  if (fd != -1) {
    write(fd,"secret data",12);
    close(fd);
  }
  return;
}

