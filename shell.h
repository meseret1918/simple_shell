#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */
typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

extern char **environ;

/** bulltin1 **/

void  exit_bul(char **cmd, char *input, char **argv, int c);
int change_dir(char **cmd, int er);
int dis_env(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);

/** function1 **/

int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
int intlen(int num);
int _atoi(char *s);
void _puts(char *str);

/** excute1 **/

int handle_builtin(char **cmd, int er);
int check_cmd(char **tokens, char *line, int count, char **argv);
void signal_to_handel(int sig);

/** excute2 **/

void read_file(char *filename, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/** cur_env **/

int path_cmd(char **line);
char *build(char *token, char *value);
char *_getenv(char *name);

/** getline **/

char *_getline(void);
void hashtag_handle(char *buff);

/** mem_aloc1 **/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);
void *_calloc(unsigned int size);

/** mem_aloc2 **/
int history(char *input);
void free_env(char **env);

/** bulltin2 **/

int history_dis(char **cmd, int er);
int print_echo(char **cmd);

/** function2 **/

int _strcmp(char *s1, char *s2);
int _isalpha(int c);
char *_itoa(unsigned int n);
void array_rev(char *arr, int len);
int _strlen(char *s);

/** function3 **/

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/** parssing **/

char **parse_cmd(char *cmd);

/** function4 **/

void print_number(unsigned int n);
void print_number_in(int n);

/** function5 **/

void prompt(void);
void print_error(char *line, int c, char **argv);

/** function6 **/

void _prerror(char **argv, int c, char **cmd);

/** main_function **/

int check_builtin(char **cmd);
void creat_envi(char **envi);

/** strtok **/

unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *tok);

#endif
