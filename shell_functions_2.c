#include "main.h"

/**
 * _strtok - A function that tokenizes a string
 * @str: string to be tokenized
 * @delimiters: delimeters to be used
 * Return: Returns the number of tokenized words.
 */

size_t _strtok(char *str, const char *delimiters)
{
	char *token;
	size_t word_count = 0;

	token = strtok(str, delimiters);

	while (token != NULL)
	{
		token = strtok(NULL, delimiters);
		++word_count;
	}
	if (token == NULL)
		handle_error("_strtok");

	return (word_count);
}

/**
 * _strArray - A function that tokenizes a string
 * @str: string to be tokenized
 * @delim: delimeters to be used
 * Return: Returns an array of tokenized words.
 */
char **_strArray(char *str, const char *delim)
{
	char **newArray = NULL;
	size_t arr_size = 0;
	size_t arr_iter = 0;
	size_t str_iter;
	int str_size = strlen(str);
	char prev_char = '\0';

	arr_size = _strtok(str, delim);

	if (arr_size > 0)
	{
		newArray = malloc((arr_size + 1) * sizeof(char *));

		if (newArray == NULL)
		{
			handle_error("malloc");
		}

		for (str_iter = 0; str_iter < str_size; ++str_iter)
		{
			if (str[str_iter] != '\0' && prev_char == '\0')
			{
				newArray[arr_iter] = &str[str_iter];
				++arr_iter;
			}

			prev_char = str[str_iter];
		}
		newArray[arr_iter] = NULL;
	}

	return (newArray);
}
