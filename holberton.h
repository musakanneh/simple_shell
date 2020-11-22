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

/* Built-in Errors */
#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

extern char **environ;
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

/**
 * struct builtInCommands - commands and functions associated with it
 * @command: input command
 * @func: output function
 */
typedef struct builtInCommands
{
    char *command;
    int (*func)(config *build);
} type_b;

/* main */
config *configInit(config *build);

/* built_ins  */
_Bool findBuiltIns(config *build);
int exitFunc(config *build);
int historyFunc(config *build);
int aliasFunc(config *build);

/* built_in_helpers*/
int countArgs(char **args);
int _atoi(char *s);

/* cd */
int cdFunc(config *);
_Bool cdToHome(config *build);
_Bool cdToPrevious(config *build);
_Bool cdToCustom(config *build);
_Bool updateEnviron(config *build); 

/* cd2 */
int updateOld(config *build);
_Bool updateCur(config *build, int index);

/* env */
int envFunc(config *build);
int setenvFunc(config *build);
int unsetenvFunc(config *build);
int _isalpha(int c);

/* help */
int helpFunc(config *build);
int displayHelpMenu(void);
int helpExit(config *build);
int helpEnv(config *build);
int helpHistory(config *build);

/* help2 */
int helpAlias(config *build);
int helpCd(config *biuld);
int helpSetenv(config *build);
int helpUnsetenv(config *build);
int helpHelp(config *build);

/* shell - */
void shell(config *build);
void validate_line(config *build);
void forkAndExecute(config *build);
// void fork_and_execute(config *build);
void strip_comments(char *str);
void convertLLtoArr(config *build);

/* _getenv */
char *_getenv(char *input, char **environ);

/* handle_errors - managing wrong user inputs*/
void handle_errors(config *build);
unsigned int countDigits(int num);
char *itoa(unsigned int num);
char *get_error_message();

/* The shell controls */
void get_null_bytes(char *str, unsigned int index);
void get_prompt(void);
void put_new_line(void);
void handle_sigint(int sigint);

/* free - functions that free allocated memories */
void free_member(config *build);
void free_args_and_buffer(config *build);
void free_args(char **args);
void free_list(linked_l *head);

/* split_string */
_Bool splitString(config *build);
unsigned int countWords(char *s);
_Bool isSpace(char c);

/* string_helpers1 */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

/* string_helpers2 */
char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *s, char c);

/* check_path */
_Bool checkPath(config *);
_Bool checkEdgeCases(config *build);

/* llfuncs1 */
linked_l *addNode(linked_l **head, char *str);
linked_l *addNodeEnd(linked_l **head, char *str);
size_t printList(const linked_l *h);
int searchNode(linked_l *head, char *str);
size_t list_len(linked_l *h);

/* llfuncs2 */
int deleteNodeAtIndex(linked_l **head, unsigned int index);
linked_l *generateLinkedList(char **array);
linked_l *addNodeAtIndex(linked_l **head, int index, char *str);
char *getNodeAtIndex(linked_l *head, unsigned int index);

/* _realloc */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* HOLBERTON_H */
