#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("newfile.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    pid_t pid = fork(); 

    if (pid == 0) { 
        printf("Child process: file descriptor = %d\n", fd);
    } else if (pid > 0) { 
        printf("Parent process: file descriptor = %d\n", fd); 
    } else { 
        perror("Error creating child process");
        exit(1);
    }

    close(fd); 

    return 0;
}
