#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	pid_t fork_pid;
	fork_pid = fork();

	if (fork_pid==-1){
		printf("ERROR FORKING!!");
	}
	else if (fork_pid == 0){
		sleep(5);
		printf("\nChild process PID: %d PPID: %d\n",getpid(), getppid());
		system("ps -f");
	}
	else{
		printf("\nParent process PID: %d PPID: %d\n",getpid(), getppid());
		system("ps -f");
	}
}

