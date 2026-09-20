
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();
	int status;
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
        printf("Child exits now.\n");
        exit(0);
    }
    else {
        printf("Parent: PID = %d\n", getpid());
        printf("Parent is sleeping...\n");

        //sleep(30);
	wait(&status);
     	printf("Child is completed\n");	
    }

    return 0;
}


