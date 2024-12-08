#include <stdio.h>
#include <unistd.h>

int main() {
  int pipefds1[2], pipefds2[2];
  int pipe_retcode1, pipe_retcode2;
  int fork_pid;
  char write_message[2][20] = {"Hi", "Hello"};
  char read_message[20];

  pipe_retcode1 = pipe(pipefds1);
  pipe_retcode2 = pipe(pipefds2);
  if (pipe_retcode1 == -1 || pipe_retcode2 == -1) {
    printf("Unable to create pipes\n");
    return 1;
  }

  fork_pid = fork();
  if (fork_pid != 0) {  // parent
    close(pipefds1[0]); // Close the unwanted pipe1 read side
    close(pipefds2[1]); // Close the unwanted pipe2 write side
    printf("In Parent: Writing to pipe 1 - Message is %s\n", write_message[0]);
    write(pipefds1[1], write_message[0], sizeof(write_message[0]));
    /*sleep(1);*/
    read(pipefds2[0], read_message, sizeof(read_message));
    printf("In Parent: Reading from pipe 2 - Message is %s\n", read_message);
    sleep(1);
  } else {              // child
    close(pipefds1[1]); // Close the unwanted pipe1 write side
    close(pipefds2[0]); // Close the unwanted pipe2 read side
    read(pipefds1[0], read_message, sizeof(read_message));
    printf("In Child: Reading from pipe 1 - Message is %s\n", read_message);
    sleep(1);
    printf("In Child: Writing to pipe 2 - Message is %s\n", write_message[1]);
    write(pipefds2[1], write_message[1], sizeof(write_message[1]));
    /*sleep(1);*/
  }

  return 0;
}