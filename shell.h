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
#define MAX_ARGS 100



extern char **environ;

int printAlpha(void);
int _strcmp(char *str1, char *str2);
char *str_cpy(const char *desti, const char *src);
void prompt(void);
ssize_t _getline(char **linepoint, size_t *p, FILE *stream);
char *path_cmd(char *cmd);
unsigned int compare_ch(char n, const char *str);
char *str_tok(char *str, const char *delim);
int str_len(const char *str);
char *str_cat(const char *dest, const char *src);
char **parse_input(char *input, size_t *arg_count);
char **get_input(void);
int main(void);
void execu(char **argv);
void handle_command(char *line);
void print_env(void);
char **tokenize(char *line);
void execute_command(char **argv);

#endif
