#include <stdio.h> /* printf() */
#include <sys/times.h>  /* times() */
#include <unistd.h>     /* sysconf() */
#include <string.h>   /* strncmp() */
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include "utility.h"

using namespace std;


int main(int argc, char* argv[])
{
  //report time part 1
  double t1, t2, cpu_time; struct tms tb1, tb2; double ticspersec;
  ticspersec = (double) sysconf(_SC_CLK_TCK);
  t1 = (double) times(&tb1);

  int maxNumOfCashiers;

  //read the flags and get the parametors from the command line
  if(argc != 3){
    printf("Incorrect invocation, please specify -n maxNumOfCashiers\n");
    return 0;
  }

  char *flag = (argv[1]);
  if(strncmp (flag,"-n", 2) == 0){
    maxNumOfCashiers = std::atoi(argv[2]);
    // printf("Depth level: %d\n", depth);
  } 
  printf("Max Num of Cashiers: %d\n", maxNumOfCashiers);
    //report time part 2
  t2 = (double) times(&tb2);
  cpu_time = (double) ((tb2.tms_utime + tb2.tms_stime) - (tb1.tms_utime + tb1.tms_stime));
  reportTime("Turnaround", (t2 - t1) / ticspersec, cpu_time / ticspersec);

  // reportAllTimestamps(timeFile, outFile);
  return 0;
}

#include <stdio.h> /* printf() */
#include <sys/times.h>  /* times() */
#include <unistd.h>     /* sysconf() */
#include <string.h>   /* strncmp() */
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include "utility.h"

using namespace std;


int main(int argc, char* argv[])
{
  //report time part 1
  double t1, t2, cpu_time; struct tms tb1, tb2; double ticspersec;
  ticspersec = (double) sysconf(_SC_CLK_TCK);
  t1 = (double) times(&tb1);

  int maxNumOfCashiers;

  //read the flags and get the parametors from the command line
  if(argc != 3){
    printf("Incorrect invocation, please specify -n maxNumOfCashiers\n");
    return 0;
  }

  char *flag = (argv[1]);
  if(strncmp (flag,"-n", 2) == 0){
    maxNumOfCashiers = std::atoi(argv[2]);
    // printf("Depth level: %d\n", depth);
  } 
  printf("Max Num of Cashiers: %d\n", maxNumOfCashiers);
    //report time part 2
  t2 = (double) times(&tb2);
  cpu_time = (double) ((tb2.tms_utime + tb2.tms_stime) - (tb1.tms_utime + tb1.tms_stime));
  reportTime("Turnaround", (t2 - t1) / ticspersec, cpu_time / ticspersec);

  // reportAllTimestamps(timeFile, outFile);
  return 0;
}

