#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) { 
        printf("Child process: Closing stdout\n");
        close(STDOUT_FILENO); 
        printf("This won't be printed\n");
        exit(0);
    }
    else if (pid > 0) { 
        printf("Parent process: Waiting for child process\n");
        wait(NULL); 
        printf("Child process has completed\n");
        exit(0);
    }
    else { 
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }

    return 0;
}

