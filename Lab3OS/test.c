#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	int fd = open("new.txt", O_WRONLY | O_CREAT ) ;
	write(fd ,"Hi" , 3);
	int rc = fork() ;
	if(rc == 0 ){
		write(fd,"Im child",strlen("Im child"));
	}else if(rc>0){
		write(fd,"Im parent",strlen("Im parent"));
	}
}
