# Holberton Shell - Simple Shell

## Description

* Holberton Shell (hsh) is a simple command line interpreter for a Linux environment.

## Project tasks  :computer:


### Authorized functions and system calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

### Compilation

The shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

### Quick start guide

To start interactive mode, type the following into the terminal:

`./hsh`

### Testing

**In interactive mode:**
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

**In non-interactive mode:**
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Repository contents

* [AUTHORS](./AUTHORS)
* [README.md](./README.md)
* [_getenv.c](./_getenv.c)
* [_strtok.c](./_strtok.c)
* [builtins_1.c](./builtins_1.c)
* [errorfuncs.c](./errorfuncs.c)
* [ffree.c](./ffree.c)
* [getargs.c](./getargs.c)
* [holberton.h](./holberton.h)
* [list_funcs.c](./list_funcs.c)
* [main.c](./main.c)
* [man_1_hsh](./man_1_hsh)
* [strfuncs.c](./strfuncs.c)

## Mandatory tasks  :wrench:

* Coding style used is [Betty](./https://github.com/holbertonschool/Betty/wiki) style.
* Simple shell 0.1 mandatory functionality
>
    Display a prompt and wait for the user to type a command. A command line always ends with a new line.
    The prompt is displayed again each time a command has been executed.
    The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
    The command lines are made only of one word. No arguments will be passed to programs.
    If an executable cannot be found, print an error message and display the prompt again.
    Handle errors.
    You have to handle the “end of file” condition (Ctrl+D)

insert pic

* Simple shell 0.2 - Handle command line with arguments



### Done:
Custom strtok\
Comments (#)\
Should not quit on Ctrl-C (Kind of done. Doesn't quit but doesn't reprint
prompt.)\
Handle arguments to exit

### To Do:
[Test Suite](https://github.com/AmilcarArmmand/shell_test_suite)
Custom getline\
Handle sentenv and unsetenv built-ins\
Handle the cd built-in\
Handle commands separator (;)\
Handle && and || shell logical operators\
Handle alias built-in\
Handle variables replacement, $?, $$\
Handle help built-in\
Handle history built-in, without arguments\
Handle file as input


#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

/**
 * struct params - parameter struct
 * @loop_count: Number of loops or inputs since the shell was started
 * @shellname: Name of the file the shell was run as
 * @args: Tokenized list of arguments from getline
 * @env: Environment
 */
typedef struct params
{
	size_t loop_count;
	char *shellname;
	char **args;
	char **env;
} param_t;

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
	void (*f)(param_t *params);
} builtin_t;

/* main */
int find_and_exec(param_t *params);
void (*get_builtin(char *name))(param_t *params);

/* builtins_1 */
void exit_shell(param_t *params);
void print_env(param_t *params);

/* _getenv */
char *check_file(param_t *params);
char *find_in_path(param_t *params);
char *_getenv(char *var, char *env[]);
char *find_in_pwd(param_t *params);

/* ffree */
void free_params(param_t *params);
void clean_exit(param_t *params, int status);
void free_env(env_t *head);
void ffree(const char *fmt, ...);

/* getargs */
char **getline_to_args(ssize_t *nbytes, FILE *stream, param_t *params);

/* listfuncs */
size_t _pow(size_t a, size_t b);
int _strcmp(char *s1, char *s2);
env_t *env_to_list(char *env[]);
env_t *add_env_node(env_t **head, char *var, char *val);
char *_getenv_node(char *var, env_t *head);

/* error funcs */
size_t _pow(size_t a, size_t b);
void stoa(size_t value, char *buffer, size_t base);
ssize_t write_error(param_t *params, char *msg);

/* strfuncs */
char *_strdup(char *);
char *_strchr(char *, char);
char *_strstr(char *haystack, char *needle);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);

/* _strtok */
int token_count(char *, char);
char **_strtok(char *str, char delim, param_t *params);
void free_array(char **tokens);

#endif /* _HOLBERTON_H_ */
