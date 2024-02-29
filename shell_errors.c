#include "main.h"
/**
 * handle_error - a function that handle errors.
 *@message: error message printed from perror.
 * Return: void.
 */

void handle_error(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);

	if (errno == EACCES)
		printf("Permission denied\n");
	else if (errno == ENOENT)
		printf("No such file or directory\n");
	else if (errno == EINVAL)
		printf("Invalid argument\n");
	else if (errno == ENOMEM)
		printf("Out of memory\n");
	else if (errno == EIO)
		printf("Input/output error");
	else if (errno == EAGAIN || errno == EWOULDBLOCK)
		printf("Resource temporarily unavailable\n");
	else
		printf("There was an error\n");
}
