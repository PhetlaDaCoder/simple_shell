#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>

#define MAX_COMM 10
#define find_path

void interpreter(char **x, char **env);
int main(int x, char **y, char **env);
int a_z(void);
void exec_command(char **argv, char **env, char **x);
void par_command(char *str, char *argv[]);
ssize_t user_input(char **str, size_t *b);
void execute_command(char ** argv, char **env, char **x);
char *find_path(char *cmd);


#endif
