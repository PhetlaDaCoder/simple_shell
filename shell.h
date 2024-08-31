#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

extern char **environ;


int printAlpha(void);
void prompt_loop(void);
char *str_tok(char *desti, const char *source);
ssize_t getline(char **line, size_t *p, FILE *stream);
int print_env(void);
void exec(char **argv);
char *path_command(char *command);
char *str_cat(char *dest, char *src);
int str_lien(char *string);
unsigned int vali_char(char ch, const char *str);
char *str_to(char *str, const char *delim);
int str_cmp(char *str1, char *str2);
char *str_cpy(char *dest, char *src);
char **parse_input(char *input, size_t *count);
void exec_command(char **args);
void sigchld_handler(int signum);
int main(void);
char **input(void);
char *find_token(char **str_ptr, const char *delim);
ssize_t _getline(char **line, size_t *size, FILE *stream);
char *construct_full_path(char *dir, char *command);
char *get_path_copy(void);
char **split_input(char *line);
char **input(void);


#endif
