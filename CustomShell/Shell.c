#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

void execute_command(char *args[]);

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  char* shell_name = "AliDinoShell";
  char* prompt_color = "\x1b[32m"; 
  char* reset_color = "\x1b[0m";    

  while (1) {
    printf("%s%s$ %s", prompt_color, shell_name, reset_color);  
    fflush(stdout);

    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      break;
    }

    line[strcspn(line, "\n")] = '\0';

    int i = 0;
    args[i] = strtok(line, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
      i++;
      args[i] = strtok(NULL, " ");
    }
    args[i] = NULL;
    execute_command(args);
    wait(&status);
  }

  return 0;
}
void execute_command(char *args[]) {
  pid_t pid;

  if (args[0] == NULL) {
    return;
  }
  if (strcmp(args[0], "exit") == 0) {
    exit(0);
  }else if (strcmp(args[0], "cd") == 0) {
    //cd command
    if (chdir(args[1]) != 0) {
      perror("cd");
    }
    return;
  }

  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    if (strcmp(args[0], "wc") == 0) {
      //wc command
      execvp("/usr/bin/wc", args);
      perror("execvp");
      exit(1);
    } else if (strcmp(args[0], "grep") == 0) {
      //grep command
      execvp("/usr/bin/grep", args);
      perror("execvp");
      exit(1);
    } else if (strcmp(args[0], "df") == 0) {
      //df command
      execvp("/bin/df", args);
      perror("execvp");
      exit(1);
    } else if (strcmp(args[0], "cmatrix") == 0) {
      //cmatrix command
      execvp("/usr/bin/cmatrix", args);
      perror("execvp");
      exit(1);
    } else if (strcmp(args[0], "ls") == 0) {
      //ls command
      execvp("/bin/ls", args);
      perror("execvp");
      exit(1);
    } else if (strcmp(args[0], "nano") == 0) {
      //nano command
      execvp("/usr/bin/nano", args);
      perror("execvp");
      exit(1);
    }else {
      printf("%s: command not found\n", args[0]);
      exit(1);
    }
  } else {
    wait(NULL);
  }
}
