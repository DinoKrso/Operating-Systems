#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    char *argv[] = { "/bin/ls", NULL };
    char *envp[] = { NULL };

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) {

        printf("execl:\n");
        execl("/bin/ls", "ls", NULL);

        printf("execle:\n");
        execle("/bin/ls", "ls", NULL, envp);

        printf("execlp:\n");
        execlp("ls", "ls", NULL);

        printf("execv:\n");
        execv("/bin/ls", argv);

        printf("execvp:\n");
        execvp("ls", argv);

        printf("execvpe:\n");
        execvpe("ls", argv, envp);

        fprintf(stderr, "exec failed\n");
        exit(1);
    } else {
    
        wait(NULL);
    }

    return 0;
}
