#include "main.h"
/**
 * wordArray - a function that tokenizes a string and
 * transform it to an array of strings.
 *
 * Return: returns an array if success.
 */
char **wordArray(void)
{
	char *line = NULL, *line_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	char *token;
	const char *delim = " \n";
	char **argv;
	int i = 0;
	int num_tokens = 0;

	printf("$ ");
	nchars_read = getline(&line, &n, stdin);

	line_copy = malloc(sizeof(char) * nchars_read);

	if (line_copy == NULL)
	{
		handle_error("tsh: memory allocation error");
	}

	strcpy(line_copy, line);

	if (nchars_read == -1)
	{
		handle_error("Exiting shell...\n");
	}
	else
	{
		token = strtok(line, delim);
	}

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}

	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(line_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;


	free(line);
	free(line_copy);
	return argv;
}
/**
 * _execute - a function that runs execve based on an array of
 * string received.
 * @argv: an array of char pointers;
 *
 * Return: -1 on failure, and void on Success.
 */
void _execute(char **argv)
{
	char *command = NULL;
	
	if (argv)
		command = argv[0];
	
	if (execve(command, argv, NULL) == -1)
	{
		handle_error("Error:");
	}

}
