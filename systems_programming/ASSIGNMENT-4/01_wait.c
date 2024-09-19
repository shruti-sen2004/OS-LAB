#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    pid_t fork_pid;
    fork_pid = fork();

    if (fork_pid == -1) {
        printf("Error forking\n");
    } else if (fork_pid == 0) {
        printf("Child process PID: %d PPID: %d\n", getpid(), getppid());
    } else {
        wait(NULL);
        printf("Parent process PID: %d PPID: %d\n", getpid(), getppid());
    }
}
