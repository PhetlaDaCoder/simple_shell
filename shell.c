#include "shell.h"

#define MAX_ARG 64

/**
 * prompt - function that prompts the user.
 */

void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 2);
}

/**
 * parse_input - a function that parses user inpit.
 * @input: pointer to user input.
 * @arg_count: total arguments counted.
 *
 * Return: total arguments.
 */

char **parse_input(char *input, size_t *arg_count)
{
	char **args = NULL;
	char *token = strtok(input, " \n");

	while (token != NULL)
	{
		args = realloc(args, (*arg_count + 1) * sizeof(char *));
		args[*arg_count] = strdup(token);
		(*arg_count)++;

		token = strtok(NULL, " \n");
	}

	args = realloc(args, (*arg_count + 1) * sizeof(char *));
	args[*arg_count] = NULL;

	return (args);
}

/**
 * get_input - reads a users input.
 *
 * Return: void.
 */

char **get_input(void)
{
	ssize_t response;
	size_t arg_count = 0, len = 0;
	char *input = NULL, **args = NULL;

	response = _getline(&input, &len, stdin);

	if (respomse == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	else if (response == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}

	args = parse_input(input, &arg_count);

	free(input);

	return (args);
}

/**
 * main - main function of the program.
 *
 * Return: 0 when done.
 *
 */

int main(void)
{
	char **args;

	pid_t pid;
	int status;
	size_t i;

int main(void)
{
	while (1)
	{
		pid_t pid;

		char *line = NULL;

		size_t n = 0;
		ssize_t char_read;

		char *argv[MAX_ARGS];

		char *token = NULL;

		int status, i = 0;

		if (issaty(STDIN_FILENO) == 1)
			prompt();

		char_read = _getline(&line, &n, stdin);
		if (char_read == -1)
		{
			perror("error. \n");
			free(line);
			exit(EXIT_FAILURE);
		}

		token = str_tok(line, " \t\n");
		while (token != NULL && i < MAX_ARG - 1)
		{
			argv[i] = token;
			token = str_tok(NULL, " \t\n");
			i++;
		}
		argv[i] = NULL;

		if (str_cmp(argv[0], "exit") == 0)
			break;
		else if (str_cmp(arg[0], "env") == 0)
		{
			print_env();
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork failure.\n");
			free(line);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execu(argv);
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid failure. \n");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		free(line);
	}

	return (0);
}



