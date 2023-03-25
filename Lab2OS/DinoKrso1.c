#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;

    pid_t pid = fork();

    if (pid == 0) { 
        printf("Child process: x = %d\n", x);
        x = 200;
        printf("Child process: x = %d\n", x); 
    } else if (pid > 0) { 
        printf("Parent process: x = %d\n", x); 
        x = 300;
        printf("Parent process: x = %d\n", x); 
    } else { 
        fprintf(stderr, "Error: fork() failed.\n");
        return 1;
    }

    return 0;
}
