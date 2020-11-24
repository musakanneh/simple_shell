# Simple Shell
What really happens when you type a command into a shell? How
does it know how to run programs and interprets user inputs? Well, you are in the right pod! This project dissects the shell program that allows you to even [explain to anyone](https://fs.blog/2012/04/feynman-technique/) without the use of the internet :) Excited? noe let's dig in!
![alt text](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)
## Description
The simple shell is an application that reads lines from either a file or the terminal, interprets them, and executes them. I most cases, it provides a command line user interface for Unix-like operating systems, where can interactively type directly to the running shell or pipe in shell scripts. [read more](https://en.wikipedia.org/wiki/Unix_shell). In this project, we designed and implemented a simple UNIX command line interpreter from the ground ^-^.

## General requirements to consider
- All our files will be compiled on Ubuntu 14.04 LTS
- Our C programs and functions will be compiled with gcc 4.8.4 using the flags ```-Wall -Werror -Wextra and -pedantic ```
- Our files ends end with a new line, with no memory leaks
- Our code will use the [Betty style](https://github.com/holbertonschool/Betty). It will be checked using ```betty-style.pl and betty-doc.pl```.
- system calls will be used when necessary ([why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))

## Program Output
- Our program have the exact same output as ```sh (/bin/sh)``` as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to the ``argv[0]``

### Example of error with sh:
```Bash
$ echo "Ian" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "Ian" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
### Same error with our program hsh:
```Bash
$ echo "kanneh" | ./hsh
./hsh: 1: qwerty: not found
$ echo "kanneh" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
## List of functions and system calls we used
```Bash 
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
```

## Project Compilation
You can compile our shell using:
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
#### Also in non-interactive mode:
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
#### Submission requirements:
1. Write a beautiful code that passes the Betty checks
2. Write a UNIX command line interpreter.

## Functionalities
#### Our Shell does the following:
- Display a prompt and wait for the user to type a command, ending wih a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, an error message is displayed to the user, and then display the prompt again.
- We will handle errors, including the “end of file” condition (Ctrl+D)

## Using the man_1_simple_shell page
- Display the page
```Bash
 man ./man_1_simple_shell
```


### Contributors
|Names                | Emails                 |
|---------------------|------------------------|
| Musa Selekie Kanneh | musas.kanneh@gmail.com |
| Obutho Ian Odhiambo | ianodhiambo9@gmail.com |
