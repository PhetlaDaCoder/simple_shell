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

#define MAX_ARGUMENTS 10
#define BUFFER_SIZE 1024
#define MAX_LINES 256

extern char **environ;


int printAlpha(void);
void prompt(void);
char *str_tok(char *desti, const char *source);
ssize_t get_line(char **line, size_t *p, FILE *stream);
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

#endif
