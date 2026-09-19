#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
int main(){
	int status;
	pid_t pid=fork();

	if(pid<0){
		printf("Failed to fork:");
		return 1;
	}
	else if(pid==0){
		printf("Child's PID: %jd\n",(intmax_t) getpid());
		exit(5);
	}
	wait(&status);
	if(WIFEXITED(status)){
		printf("First child STATUS:%d\n",WEXITSTATUS(status));
	}
	pid=fork();
	if(pid<0){
		printf("Failed to fork:");
                return 1;
	}
	else if(pid==0){
		printf("new Child's PID: %jd\n",(intmax_t) getpid());
                exit(12);
        }
	waitpid(pid,&status,0);
	if(WIFEXITED(status)){
                printf("Second child STATUS:%d\n",WEXITSTATUS(status));
        }
	
	printf("Parent's PID: %jd\n",(intmax_t) getpid());
	return 0;
}
