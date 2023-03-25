#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2,;

    pid1 = fork(); 

    if (pid1 == 0) { 
        printf("Child 1 is running\n");
        sleep(3);
        printf("Child 1 is done\n");
        exit(1);
    }
    else { 
        pid2 = fork(); 

        if (pid2 == 0) { 
            printf("Child 2 is running\n");
            sleep(1);
            printf("Child 2 is done\n");
            exit(2);
        }
        else { 
            waitpid(pid1,0); 
            printf("Parent waited for Child 1. Status: %d\n");
            
            waitpid(pid2,0); 
            printf("Parent waited for Child 2. Status: %d\n");
            
            printf("Parent is done\n");
            exit(0);
        }
    }

    return 0;
}