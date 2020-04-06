#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

char *str_concat(char *s1, char *s2);
int _strlen(char *s);
int token_count(char *, char);
char **_strtok(char *, char);
void free_array(char **tokens);
char *_getenv(char *var, char *env[]);

#endif /* _HOLBERTON_H_ */
