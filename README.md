# Holberton Shell - Simple Shell

## Description

* Holberton Shell (hsh) is a simple command line interpreter for a Linux environment.  Hsh works like 

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

**Syntax**

To display man page: `man ./man_1_simple_shell`

Commands can be given to the shell with the general syntax: `command_name {arguments}`

**Built-ins implemented**

There are several built-in commands used for job control incorporated into hsh.

* env, setenv, unsetenv

* exit - To exit the hsh shell, the user may use the exit built-in. Exit can be given a status number, and if no number is given, the status is that of the last command executed. 
`exit'

To exit out of a process or command, ctrl c is used. Control-C interrupts a process and causes it to abort.

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

## Test suite

[Test suite](./https://github.com/AmilcarArmmand/shell_test_suite)

## Mandatory tasks

### Coding style used is [Betty](./https://github.com/holbertonschool/Betty/wiki) style.

### 3. Simple shell 0.1 functionality

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.

* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (Ctrl+D)
