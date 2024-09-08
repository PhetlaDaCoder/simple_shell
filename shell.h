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
#define MAX_ARG 64


extern char **environ;

int printAlpha(void);
int str_cmp(char *str1, char *str2);
char *str_cpy(char *desti, char *src);
void prompt (void);
int print_env(void);
ssize_t _getline(char **linepoint, size_t *p, FILE *stream);
static int resize_buffer(char **linepoint, size_t *p);
char *path_cmd(char *cmd);
static int init_buffer(char **linepoint, size_t *p, size_t buf_size);
static int read_ch(char **linepoint, size_t *p, ssize_t *ch_read, FILE *stream);
unsigned int compare_ch(char n, const char *str);
char *str_tok(char *str, const char *delim);
int str_len(char *str);
char *str_cat(char *dest, char *src);
char **parse_input(char *input, size_t *arg_count);
char **get_input(void);
int main();
int main (void);
void execu(char **argv);
#endif
