#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int rc = fork() ;
	if(rc == 0){
		sleep(15);
		printf("Child pid %d\n", getpid());
		printf("My parent pid %d\n",getppid());
	}else if (rc>0){
		printf("Parent pid %d\n ",getpid());
		printf("My child pid %d\n ", rc);
	}

	return 0; 
}
