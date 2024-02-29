#ifndef MAIN_h
#define MAIN_h

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* testing */
char **wordArray(void);
void _execute(char **argv);
void handle_error(const char *message);

/**************************/

int _fork(void);
int _wait(void);
char *_getline(void);
void _execve(char *path, char **av, char **env);
/*size_t _getline(char **line, size_t *n, FILE *stream);*/
size_t _strtok(char *str, const char *delimiters);
char **_strArray(char *str, const char *delim);

#endif
