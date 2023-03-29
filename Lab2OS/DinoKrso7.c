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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    pid_t pid1, pid2;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // First child process
        close(fd[0]); // Close unused read end of pipe
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to write end of pipe
        execlp("ls", "ls", NULL); // Execute ls command
        exit(EXIT_FAILURE);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Second child process
        close(fd[1]); // Close unused write end of pipe
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to read end of pipe
        execlp("wc", "wc", "-l", NULL); // Execute wc -l command
        exit(EXIT_FAILURE);
    }

    // Parent process
    close(fd[0]); // Close unused read end of pipe
    close(fd[1]); // Close unused write end of pipe
    waitpid(pid1, NULL, 0); // Wait for first child to finish
    waitpid(pid2, NULL, 0); // Wait for second child to finish

    return 0;
}
