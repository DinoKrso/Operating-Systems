#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    printf("parent in pid: (%d)\n", (int)getpid());
    int p1[2];
    
 

    char buff1[100];
    char buff2[100];
    int rc = fork();
    if (rc == 0)
    {
        int fd = open("test1.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        printf("%d\n", fd);
        fflush(stdout);
        close(p1[0]);
      	 write(p1[1],"Cao\n ",5);
        fflush(stdout);
        int n = read(STDIN_FILENO, buff1, sizeof buff1);
        write(fd, buff1, n);
    }
   
        int rc2 = fork();
        if (rc2 == 0)
        {
            int fd2 = open("test2.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
            printf("%d\n", fd2);
            fflush(stdout);
          	 close(p1[1]);
	  	 write(p1[0],"Bye",3);
            fflush(stdout);
            int n = read(STDIN_FILENO, buff2, sizeof buff2);
            write(fd2, buff2, n);
        }
        
            printf("final parent in pid: (%d)\n", (int)getpid());
		close(p1[0]);
       		 close(p1[1]);
            waitpid(rc, NULL, 0);
            waitpid(rc2, NULL, 0);
        
;
    return 0;
}
