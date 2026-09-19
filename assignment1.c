#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
int main(){
	pid_t pid=fork();
	if(pid<0){
		printf("Failed to fork:");
		return 1;
	}
	else if(pid==0){
		printf("Child's PID: %jd\n",(intmax_t) getpid());
		exit(0);
	}
	printf("Parent's PID: %jd\n",(intmax_t) getpid());
	return 0;
}
