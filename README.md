# Simple Shell
In this project, will will implementing a simple shell.

_This work constitutes the second project of the Low-level programming & Algorithm ― Linux and Unix system programming ― of the ALX-Holberton Software Engineering program._

## General Requirements
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Our C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All our files ends end with a new line, with no memory leaks
- Our code will use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Our files contain no more than 5 functions
- Our header files will be include guarded
- system calls will be used when necessary ([why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))

## Program Output
- Our program have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

>### Example of error with sh:
```Bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
>### Same error with your program hsh:
```Bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
## List of allowed functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Compilation
Our shell will be compiled this way:
```Bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## Testing
Our shell should work like this in interactive mode:
```Bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
### Also, in non-interactive mode:
```Bash
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
## The Project's Implementation in Review
> ### Submission requirements:
1. Write a beautiful code that passes the Betty checks
2. Write a UNIX command line interpreter.

> ### Our Shell will have to:
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- We will handle handle errors.
- We have to handle the “end of file” condition (Ctrl+D)

> ### Oue Shell will not have to:
- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments
3. Simple shell 0.1 +
    - Handle command lines with arguments
4. Simple shell 0.2 +
    - Handle the PATH
5. Simple shell 0.3 +
    - Implement the exit built-in, that exits the shell
    - Usage: exit
    - You don’t have to handle any argument to the built-in exit
6. Simple shell 0.4 +
    - Implement the env built-in, that prints the current environment

## Contributors:
|Names                | Emails                 |
|---------------------|------------------------|
| Musa Selekie Kanneh | musas.kanneh@gmail.com |
| Obutho Ian Odhiambo | ianodhiambo9@gmail.com |
