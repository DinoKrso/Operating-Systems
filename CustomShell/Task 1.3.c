#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    printf("Parent process (PID %d) is starting...\n", getpid());

    pid = fork();

    if (pid < 0) { 
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) { 
        printf("Child process (PID %d) is starting...\n", getpid());
        execlp("/bin/ls", "ls", "-l", NULL); 
        fprintf(stderr, "Execution failed\n"); 
        exit(1);
    } else {
        printf("Parent process (PID %d) is waiting for child (PID %d) to finish...\n", getpid(), pid);
        wait(&status); 
        printf("Child process (PID %d) has finished with status %d\n", pid, status);
    }

    printf("Parent process (PID %d) is exiting...\n", getpid());
    return 0;
}
