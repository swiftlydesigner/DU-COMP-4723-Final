
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* DISPLAY WARNING: Type casts are NOT being printed */

void read_running_processes_on_comp(void)

{
  int fd;
  ssize_t read;
  char line [1024];
  ssize_t dummy2;
  int dummy;
  
  fd = open("/proc/self/maps",0);
  if (fd != -1) {
                    /* Read line-by-line the running procceses
                       on the device. */
    while (read = ::read(fd,line,1023), 0 < read) {
      line[read] = '\0';
                    /* Print the read process
                        */
      printf("%s",line);
    }
    close(fd);
  }
  return;
}

