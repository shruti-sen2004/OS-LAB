#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t fork_pid;
	fork_pid = fork();

	if (fork_pid==-1){
		printf("ERROR FORKING!!");
	}
	else if (fork_pid == 0){
		printf("\nChild process PID: %d PPID: %d\n",getpid(), getppid());
		system("ps -f");
	}
	else{
		wait(NULL);
		printf("\nParent process PID: %d PPID: %d\n",getpid(), getppid());
		system("ps -f");
	}
}

