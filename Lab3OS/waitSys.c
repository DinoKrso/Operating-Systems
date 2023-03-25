#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int rc = fork();
	if(rc == 0){
		write(1,"Hello",5) ;
	}else if (rc>0){
		wait(NULL) ;
		write(1,"Goodbye",7);
	} 
	return 0 ; 
}
