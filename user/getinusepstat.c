#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"
/*
  prints the pstat for all inuse processes
*/
int main(int argc, char *argv[])
{
  struct pstat stats; // initializes pstat struct stats
  getpstat(&stats);  // get pstat from kernel
  int procCount = pcount();  // get the amount of processes in use
  for (int i = 0; i < procCount; i++) // iterate through working processes (will be at begining of struct)
  {
    printf("inuse: ");  
    if (stats.inuse[i])  // print true if proc is in use
      printf("true\n");
    else  // print false if not
      printf("false\n");

    printf("pid: %d\n", stats.pid[i]);  // print proc pid
    printf("nice: %d\n\n", stats.nice[i]); // print proc nice valuse
  }

  exit(0);
}
