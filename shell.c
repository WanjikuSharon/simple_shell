#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - display the prompt
 * execute_command - Execute user input
 * @data: pointer to the structure of data
 * @args: number of arguments pased to the program execution
 * @token: variable for tokens available in string
 * fork - create child process
 * perror - handle errors
 * execve - command execution
 * perror - handle errors
 */

void display_prompt(void)
{
	printf("simple_shell$ ");
}

int execute_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL && i < MAX_COMMAND_LENGTH - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork error");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Command execution error");
			return (-1);
		}
	}
	}
	else
	{

	int status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("Waitpid error");
		return (-1);
	}

	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
	{
		printf("Command terminated with signal %d\n", WTERMSIG(status));
		return (-1);
	}
	}

	return (0);
}

/**
 * main - entry point of the program
 * @command_length: number of values received from the command line
 * @command: buffer for memory allocation
 * display_prompt - Display the prompt
 * Return: zero on succes.
 * getline - Read user input
 */

int main(void)
{
	size_t command_length = 0;
	char *command = NULL; /*Buffer memory*/

	while (1)
	{
		display_prompt();
	}
	/*Read user input using getline*/

	if (getline(&command, &command_length, stdin) == -1)
	{
	/*Handle end of file (Ctrl+D)*/
		printf("\n");
		break;
	}
	command[strcspn(command, "\n")] = '\0';

	int result = execute_command(command);

	if (result != 0)
	{
		printf("Command execution failed.\n");
	}

	free(command);
	command = NULL;
	command_length = 0;

	}
	return (0);
	}

	int result = execute_command(command);

	if (result != 0)
	{
		printf("Command execution failed.\n");
	}

	free(command);
	command = NULL;
	command_length = 0;
	}

	return (0);
}
