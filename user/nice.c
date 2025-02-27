#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
// Running nice on the user side. Giving command line arguments and get return value.
int
main(int argc, char *argv[])
{
  // if the argument count is less than defined value, exit program
  if(argc < 3){
    printf("Too few arguments\n");
    exit(1);
  }

  nice(atoi(argv[1])); // converts argument at index 1 of argv array to an integer so it could be used as the nice value.

  int progargc = argc - 1;  // gets amount of arguments for new program
  char *progargv[progargc]; // stores argument for  new program

  for(int i = 0; i < progargc - 1; i++) { // iterates through new program arguments
      progargv[i] = argv[i + 2]; // adds arguments to progargv
  }
  progargv[progargc - 1] = 0;  // add 0 to end of progarg v

  
  exec(argv[2], progargv); // execute new prgram

  exit(0);
}
