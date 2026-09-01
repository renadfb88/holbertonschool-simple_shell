#include "shell.h"

/**
 * read_line - Reads a line of input from standard input
 *
 * Return: Pointer to the line buffer, or NULL on EOF/error
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&line, &bufsize, stdin);
	if (characters == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * split_line - Splits a line into tokens (arguments)
 * @line: The input string to parse
 *
 * Return: Null-terminated array of token strings, or NULL on error
 */
char **split_line(char *line)
{
	size_t bufsize;
	int position = 0;
	char **tokens;
	char *token;

	bufsize = (strlen(line) / 2) + 2;
	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position++] = token;
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * free_args - Frees the memory allocated for the arguments array
 * @args: Array of token pointers returned by split_line
 *
 * Description: The tokens point inside the buffer returned by read_line,
 * so only the array of pointers itself is freed here.
 */
void free_args(char **args)
{
	if (args)
		free(args);
}
