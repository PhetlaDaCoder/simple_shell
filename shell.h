#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 8

int main(void);
int interpreter(void);
void prs_input(char *line, char *args[]);
void exe_command(char *args[]);


#endif
