#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;
    int status1, status2;

    child1=fork();
    if(child1<0){
	    perror("FFailed");
	    return 1;
    }
    else if(child1==0){
	    printf("Child 1 PID:%d\n",getpid());
	    exit(10);
    }
    child2=fork();
    if(child2<0){
	    perror("FFAILED2");
	    return 1;
    }
    else if(child2==0){
	    printf("Child 2 PID:%d\n", getpid());
	    exit(20);
    }
    printf("Parent PID:%d waiting children...\n", getpid());
    waitpid(child1,&status1,0);
    printf("Parent PID:%d after child1 has finished:\n",child1);
    if(WIFEXITED(status1)){
	    int exit_code1=WEXITSTATUS(status1);
	    if(exit_code1==0){
		    printf("	Normal exit Status:%d\n",exit_code1);
	    }
	    else{
		    printf("	Error exit Status:%d\n",exit_code1);
	    }
    }
    else{
	    printf("	Status: Abnormal termination:\n");
    }
    waitpid(child2,&status2,0);
    printf("Parent PID:%d after child2 has finished:\n",child2);
    if(WIFEXITED(status2)){
            int exit_code2=WEXITSTATUS(status1);
            if(exit_code2==0){
                    printf("   Normal exit Status:%d\n",exit_code2);
            }
            else{
                    printf("    Error exit Status:%d\n",exit_code2);
            }
    }
    else{
            printf("    Status: Abnormal termination:\n");
    }
    printf("Parent Exit:\n");
    return 0;
}


