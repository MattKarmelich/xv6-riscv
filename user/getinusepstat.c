#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"
/*
  prints the pstat for all inuse processes
*/
int main(int argc, char *argv[])
{
  struct pstat stats;
  getpstat(&stats);
  int procCount = pcount();
  for (int i = 0; i < procCount; i++)
  {
    printf("inuse: ");
    if (stats.inuse[i])
      printf("true\n");
    else
      printf("false\n");

    printf("pid: %d\n", stats.pid[i]);
    printf("nice: %d\n\n", stats.nice[i]);
  }

  exit(0);
}
