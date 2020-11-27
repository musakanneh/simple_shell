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

/* --- Built-in Errors --- */
#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

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
 * @env_list: array of env variables to put into execve
 * @args: array of argument strings
 * @buffer: string buffer of user input
 * @path: array of $PATH locations
 * @full_path: string of path with correct prepended $PATH
 * @shell_name: name of shell (argv[0])
 * @count_line: counter of lines users have entered
 * @error_status: error status of last child process
 */
typedef struct configurations
{
	linked_l *env;
	char **env_list;
	char **args;
	char *buffer;
	char *path;
	char *full_path;
	char *shell_name;
	unsigned int count_line;
	int error_status;
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

/* --- main --- */
config *config_init(config *build);

/* --- built_ins --- */
_Bool find_built_ins(config *build);
int exit_function(config *build);
int history_function(config *build);
int alias_function(config *build);

/* --- built_in_controls --- */
int count_args(char **args);
int _atoi(char *s);

/* --- cd --- */
int implement_cd(config *);
_Bool cd_to_home(config *build);
_Bool cd_to_previous(config *build);
_Bool cd_to_custom(config *build);
_Bool update_environ(config *build);

/* --- cd2 --- */
int update_old(config *build);
_Bool update_cur_dir(config *build, int index);

/* --- env_variables --- */
int env_function(config *build);
int set_env_func(config *build);
int unset_env_func(config *build);
int is_alpha(int c);

/* --- help_funs --- */
int help_function(config *build);
int display_help_menu(void);
int help_guide_exit(config *build);
int help_env(config *build);
int help_history(config *build);

/* --- help_funs2 --- */
int help_alias(config *build);
int help_cd(config *biuld);
int help_set_env(config *build);
int help_unset_env(config *build);
int help_guide(config *build);

/* --- shell --- */
void shell(config *build);
void validate_line(config *build);
void fork_and_execute(config *build);
void strip_comments(char *str);
void convert_llist_to_arr(config *build);

/* _getenv */
char *_getenv(char *input, char **environ);

/* handle_errors - managing wrong user inputs*/
void handle_errors(config *build);
unsigned int count_num_digits(int num);
char *itoa(unsigned int num);
char *get_error_message();

/* shell_controls */
void get_null_bytes(char *str, unsigned int index);
void get_prompt(void);
void put_new_line(void);
void handle_sigint(int sigint);

/* --- free --- */
void free_member(config *build);
void free_args_and_buffer(config *build);
void free_args(char **args);
void free_list(linked_l *head);

/* --- split_string --- */
_Bool split_string(config *build);
unsigned int count_words(char *s);
_Bool is_space(char c);

/* --- string_controls --- */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

/* --- string_controls2 --- */
char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *s, char c);

/* --- check_path --- */
_Bool check_path(config *);
_Bool validate_constraints(config *build);

/* --- linkedlist_funs1 --- */
linked_l *add_node_to_front(linked_l **head, char *str);
linked_l *add_node_to_end(linked_l **head, char *str);
size_t print_list(const linked_l *h);
int search_node(linked_l *head, char *str);
size_t list_len(linked_l *h);

/* --- linkedlist_funs2 --- */
int delete_node_at_index(linked_l **head, unsigned int index);
linked_l *generateLinkedList(char **array);
linked_l *add_node_at_index(linked_l **head, int index, char *str);
char *get_node_at_index(linked_l *head, unsigned int index);

/* --- _realloc --- */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* HOLBERTON_H */