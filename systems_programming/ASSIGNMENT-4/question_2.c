#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t pid1;
  pid1 = fork();
  if (pid1 == 0) {
    while (1) {
      printf("child1 is active\n");
      sleep(1);
    }
  }

  pid_t pid2;
  pid2 = fork();
  if (pid2 == 0) {
    while (1) {
      printf("child2 is active\n");
      sleep(1);
    }
  }

  sleep(2);
  kill(pid1, SIGSTOP); // suspension
  printf("\nINFO: child1 stopped\n");
  sleep(2);
  kill(pid1, SIGCONT); // resumption
  printf("\nINFO: child1 resumed\n");
  sleep(2);

  kill(pid1, SIGINT); // termination
  printf("\nINFO: child1 killed\n");
  kill(pid2, SIGINT); // termination
  printf("\nINFO: child2 killed\n");
}