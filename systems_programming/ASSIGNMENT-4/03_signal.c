#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal) {
    printf("Caught the signal %d\n", signal);
}

int main(void) {
    signal(SIGINT, signal_handler);
    while(1);
}