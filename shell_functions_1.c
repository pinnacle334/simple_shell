#include "main.h"

/**
 * _fork - a function that executes the fork command
 * Return: Aways 0.
 */
int _fork(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		handle_error("fork");
	}
	return (pid);
}
/**
 * _wait - a function that executes the wait system call.
 * Return: Aways 0.
 */
int _wait(void)
{
	int status = 0;
	pid_t child_pid;
	int exit_status = 0;

	child_pid = wait(&status);
	if (child_pid == -1)
	{
		handle_error("Waiting error encountered");
	}
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	else
		printf("child did not extit normally\n");

	return (child_pid);
}

/**
 * _execve - a function that executes the execve system call
 * @path: command to execute.
 * @av: pointer to array of chars
 * @env: enviromental variables.
 * Return: Aways 0.
 */
void _execve(char *path, char **av, char **envp)
{

	if (execve(path, av, envp) == -1)
	{
		handle_error("execve");
	}
}

/**
 * _getline - a function that executes the getline()
 * Return: Aways read line on success.
 */
char *_getline(void)
{
	ssize_t readline;
	char *line = NULL;
	size_t n = 0;

	readline = getline(&line, &n, stdin);
	if (readline == -1)
	{
		free(line);
		return NULL;
	}
	if (readline == 0)
	{
		free(line);
		return (NULL);
	}
	/**
	 * if (readline > 0 && (*line)[readline - 1] == 10)
		(*line)[readline - 1] = '\0';
	*/
	if (readline > 0l && line[readline - 1] == '\n')
		line[readline - 1] = '\0';

	return (line);
}
