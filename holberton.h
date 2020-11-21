#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

/* Built-in errors */
#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

/* string control functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(char *s, char c);
char *itoa(unsigned int n);
int intlen(int num);
void rev_arr(char *arr, int len);

extern char **environ;

/**
 * struct linkedList - linked list data structure
 * @string: environ variable path name
 * @next: pointer to next node
 */
typedef struct linkedList
{
    char *string;
    struct linkedList *next;
} linked_l;

/**
 * struct configurations - configuration of build settings
 * @env: linked list of local env variables
 * @envList: array of env variables to put into execve
 * @args: array of argument strings
 * @buffer: string buffer of user input
 * @path: array of $PATH locations
 * @fullPath: string of path with correct prepended $PATH
 * @shellName: name of shell (argv[0])
 * @lineCounter: counter of lines users have entered
 * @errorStatus: error status of last child process
 */
typedef struct configurations
{
    linked_l *env;
    char **envList;
    char **args;
    char *buffer;
    char *path;
    char *fullPath;
    char *shellName;
    unsigned int lineCounter;
    int errorStatus;
} config;

/* The shell file */
void shell(config *build);
void validate_line(config *build);
void fork_and_execute(config *build);
void strip_comments(char *str);
void convertLLtoArr(config *build);

/* The shell controls file */


/* handle_errors - managing wrong user inputs*/
void handle_errors(config *build);
unsigned int countDigits(int num);
char *itoa(unsigned int num);
char *get_error_message();

/* free - functions that free allocated memories */
void free_member(config *build);

#endif /* HOLBERTON_H */
