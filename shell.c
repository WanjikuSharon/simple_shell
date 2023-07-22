#include "shell.h"

#define MAX_COMMAND_LENGTH 100

//Display shell prompt
void display_prompt() {
    printf("simple_shell$ ");
}
int execute_command(char *command) {
    // Split the command into arguments (if any)
    char *args[MAX_COMMAND_LENGTH];
    char *token;
    int i = 0;

    token = strtok(command, " ");
    while (token != NULL && i < MAX_COMMAND_LENGTH - 1) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Fork to create a child process for command execution
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork error");
        return -1;
    } else if (pid == 0) {
        // Child process
        // Execute the command using execve
    if (execve(args[0], args, NULL) == -1) {
        // If execve fails, print an error message
        perror("Command execution error");
        return -1;
    }
        }
    }
    else
    {
        // Parent process
        int status;
        // Wait for the child process to complete
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("Waitpid error");
            return -1;
    }
    // Check if the child process terminated normally
        if (WIFEXITED(status))
        {
            // Command executed successfully (exit code available in WEXITSTATUS(status))
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status))
        {
            // Command terminated due to a signal
            printf("Command terminated with signal %d\n", WTERMSIG(status));
            return -1;
        }
    }

    return 0;
}
int main()
{
    size_t command_length = 0;
    char *command = NULL; // Buffer memory

    while (1)
    {
        display_prompt();
    }
    // Read user input using getline
        if (getline(&command, &command_length, stdin) == -1) {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }
        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Process the user input and execute the command
        int result = execute_command(command);
        if (result != 0) {
            printf("Command execution failed.\n");
        }

        // Free the allocated memory for the command line
        free(command);
        command = NULL;
        command_length = 0;
    }

    return 0;
}// Process the user input and execute the command
        int result = execute_command(command);
        if (result != 0) {
            printf("Command execution failed.\n");
        }

        // Free the allocated memory for the command line
        free(command);
        command = NULL;
        command_length = 0;
    }

    return 0;
}
