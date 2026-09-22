#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

static void reap_background_children(void)
{
    int status;
    pid_t child_pid;

    while ((child_pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("[background process %d finished]\n", child_pid);
    }
}

int main(void)
{
    char input[MAX_LINE];
    char *args[MAX_ARGS];

    while (1) {
        int argc = 0;
        int background = 0;

        reap_background_children();

        printf("mysh> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        char *token = strtok(input, " \t");
        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc++] = token;
            token = strtok(NULL, " \t");
        }
        args[argc] = NULL;

        if (argc == 0) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) {
            break;
        }

        if (strcmp(args[argc - 1], "&") == 0) {
            background = 1;
            args[--argc] = NULL;
        }
        else {
            size_t length = strlen(args[argc - 1]);
            if (length > 0 && args[argc - 1][length - 1] == '&') {
                background = 1;
                args[argc - 1][length - 1] = '\0';

                if (args[argc - 1][0] == '\0') {
                    args[--argc] = NULL;
                }
            }
        }

        if (argc == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            execvp(args[0], args);

            perror("execvp");
            _exit(EXIT_FAILURE);
        }

        if (!background) {
            int status;
            pid_t result;

            do {
                result = waitpid(pid, &status, 0);
            } while (result == -1 && errno == EINTR);

            if (result == -1) {
                perror("waitpid");
            }
        } else {
            printf("[background process %d started]\n", pid);
        }
    }

    return 0;
}
