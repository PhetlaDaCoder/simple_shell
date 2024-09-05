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
int str_cmp(char *str1, char *str2);
char *str_cpy(char *desti, char *src);
void prompt (void);
int print_env(void);
ssize_t _getline(char **linepoint, size_t *p, FILE *stream);

#endif
