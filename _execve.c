#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(program_data *data)
{
	int status, retrieve = 0;
	pid_t young_pid;

	retrieve = inbuilt(data);
	if (retrieve != -1)
		return (retrieve);

	retrieve = search_path(data);
	if (retrieve)
	{
		return (retrieve);
	}
	else
	{
		young_pid = fork();
		if (young_pid == -1)
		{
			perror(data->command_input);
			exit(EXIT_FAILURE);
		}
		if (young_pid == 0)
		{
			retrieve = execve(data->tokens[0], data->tokens, data->enviro);
			if (retrieve == -1)
				perror(data->command_input),
					exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
