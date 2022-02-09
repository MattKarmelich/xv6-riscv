// Create a zombie process that
// must be reparented at exit.

/*
  Name: Matt Karmelich

  The process count will always be different,
  with the first print statement being one lower 
  than the second print statement.
  
  This is because the first statement is before the
  child process is created.  At the time of the second,
  the child process exists, and all though it has exited,
  it still exists as a zombie.
*/

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int count;

  count = pcount();
  printf("%d\n", count);  //  First print statement
  if(fork() > 0) {
    sleep(5);  // Let child exit before parent.
    count = pcount();
    printf("%d\n", count);  //  Second print statement
  }
  exit(0);
}
