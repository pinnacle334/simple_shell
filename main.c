#include "main.h"

/**
 * main - A simple shell program.
 * @argc: argument counts
 * @argv: pointer to an aray of chars
 * @env: environment vairiables.
 * Return: Always 0.
 */

int main(int argc, char **argv, char **env)
{
	char *line;

	env = NULL;

	printf("$ ");

	while ((line = _getline()) != NULL)
	{
		pid_t pid = _fork();

		if (pid == 0)
		{
			if (argc < 1)
				handle_error("Aleast two argument needed\n");

			char *command = line;

			_execve(command, argv, env);
		}
		pid_t child_pid = _wait();

		printf("$ ");
		free(line);
	}


	return (0);
}
