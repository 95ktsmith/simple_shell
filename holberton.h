#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

/**
 * struct env_node - Environment node struct
 * @var: Envrionment variable name
 * @val: Variable value
 * @next: Next node in linked list
 */
typedef struct env_node
{
	char *var;
	char *val;
	struct env_node *next;
} env_t;

/**
 * struct builtin - Builtin function struct
 * @name: Name of the builtin command
 * @f: The Function associated with that name
 */
typedef struct builtin
{
	char *name;
	void (*f)(char *args[], char *env[], size_t cmd_num);
} builtin_t;

/* main */
int find_and_exec(char *argv[], char *args[], char *env[], size_t cmd_num);
void (*get_builtin(char *name))(char *args[], char *env[], size_t cmd_num);

/* builtins_1 */
void exit_shell(char *args[], char *env[], size_t cmd_num);
void print_env(char *args[], char *env[], size_t cmd_num);

/* _getenv */
char *check_file(char *filename, char *path);
char *find_in_path(char *filename, char *path);
char *_getenv(char *var, char *env[]);

/* getargs */
char **getline_to_args(ssize_t *nbytes, FILE *stream);

/* listfuncs */
size_t _pow(size_t a, size_t b);
int _strcmp(char *s1, char *s2);
env_t *env_to_list(char *env[]);
env_t *add_env_node(env_t **head, char *var, char *val);
char *_getenv_node(char *var, env_t *head);

/* error funcs */
size_t _pow(size_t a, size_t b);
void stoa(size_t value, char *buffer, size_t base);
ssize_t write_error(char *shellname, char *cmd_name,
		    size_t cmd_num, char *msg);

char *check_file(char *filename, char *path);
char *find_in_path(char *filename, char *path);

/* strfuncs */
char *_strdup(char *);
char *_strchr(char *, char);
char *_strstr(char *haystack, char *needle);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);

/* _strtok */
int token_count(char *, char);
char **_strtok(char *, char);
void free_array(char **tokens);

#endif /* _HOLBERTON_H_ */
