#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * interpreter - prompts a user to enter a command with arguments and executes it.
 * Return: 0 when done.
 */

int interpreter(void)
{
    char *line = NULL;
    size_t length = 0;
    ssize_t reader;
    char *args[8];
    int x;
    pid_t pid;
    int status;

    while (1)
    {
        write(STDOUT_FILENO, " # ", 3); 

        reader = getline(&line, &length, stdin);
        if (reader == -1)  // Handle EOF (Ctrl+D)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        // Tokenize input line into command and arguments
        x = 0;
        args[x] = strtok(line, " \n");
        if (args[x] == NULL)  // No input, just press Enter
        {
            continue;
        }
        while (args[x] != NULL && x < 7)
        {
            x++;
            args[x] = strtok(NULL, " \n");
        }
        args[x] = NULL;

        // Create a child process to execute the command
        pid = fork();
        if (pid == -1)
        {
            perror("Error forking");
            continue;
        }

        if (pid == 0)
        {
            // Execute the command
            if (execve(args[0], args, NULL) == -1)
            {
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
    }

    free(line);
    return (0);
}
 
