#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  struct timeval start_time;
  struct timeval finish_time;
  int start;
  int finish;
  int rc = fork();
  char *p[argc];
  for (int i=1; i < argc; i++){
    p[i-1]= argv[i];
  }
  p[argc-1] = NULL;
  gettimeofday(&start_time, NULL);
  start = start_time.tv_usec;
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    execvp(argv[1], p);  
  } else {
    wait(NULL);
    gettimeofday(&finish_time, NULL);
    finish = finish_time.tv_usec;
    printf("Elapsed time: : %i \n", finish - start);
  }
  return 0;
}


