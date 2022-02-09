#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
// add documentation
int
main(int argc, char *argv[])
{
  
  if(argc <= 2){
    exit(0);
  }

  nice(atoi(argv[1]));

  int progargc = argc - 1;
  char *progargv[progargc];

  for(int i = 0; i < progargc - 1; i++) {
      progargv[i] = argv[i + 2];
  }
  progargv[progargc - 1] = 0;

  
  exec(argv[2], progargv);

  exit(0);
}
