#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

size_t _pow(size_t a, size_t b);
void stoa(size_t value, char *buffer, size_t base);
ssize_t not_found(char *shellname, char *cmd_name, size_t cmd_num);
char *check_file(char *filename, char *path);
char *find_in_path(char *filename, char *path);
char *_strdup(char *);
char *_strchr(char *, char);
char *_strstr(char *haystack, char *needle);
char **stdintoargs(ssize_t *nbytes);
void ffree(const char *fmt, ...);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
int token_count(char *, char);
char **_strtok(char *, char);
void free_array(char **tokens);
char *_getenv(char *var, char *env[]);

#endif /* _HOLBERTON_H_ */
