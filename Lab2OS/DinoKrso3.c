#include <stdio.h>
#include <unistd.h>

int main() {
    printf("hello"); 

    pid_t pid = fork(); 

    if (pid == 0) { 
        printf("hello\n"); 
    } else if (pid > 0) { 
        printf("goodbye\n"); 
    } 

    return 0;
}
