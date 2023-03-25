#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>

int main(){
	int rc = fork();
	if (rc == 0){
		char *args[2];
		args[0] = strdup("/bin/ls") ;
		args[1] = NULL ; 
		execvp(args[0] , args) ;
		printf("this doesnt exists");
	}else if (rc>0){
		printf("parent\n");
}


return 0;
}
