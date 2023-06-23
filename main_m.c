#include "monty.h"
#include <stdio.h>

globales_t globalvar = {NULL, NULL, NULL};

/**
 * main - entr pt for the  program
 * @argc: count of arguments passe to  programm
 * @argv: pointer 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	char *token = NULL;
	size_t line_buf_size = 0;
	int line_num = 0, flag = 0, flag2 = 0;
	ssize_t line_size;
	stack_t *stack = NULL;

	if (argc != 2)
		m_stderr_usage();
	globalvar.fd = fopen(argv[1], "r");
	if (globalvar.fd == NULL)
		m_stderr_fopen(argv[1]);
	line_size = getline(&globalvar.line_buf, &line_buf_size, globalvar.fd);
	if (globalvar.line_buf[0] == '#')
		line_size = getline(&globalvar.line_buf, &line_buf_size, globalvar.fd);
	while (line_size >= 0)
	{flag = 0;
		flag2 = 0;
		line_num++;
		token = strtok(globalvar.line_buf, DELIM);
		globalvar.token2 = strtok(NULL, DELIM);
		if (token == NULL)
		{flag2 = 1;
			m_nop(&stack, line_num); }
		if (flag2 == 0)
		{
			if (token[0] == '#')
			{
				line_size = getline(&globalvar.line_buf,
						    &line_buf_size, globalvar.fd);
				flag = 1; }}
		if (flag == 0)
		{m_get_builtin(token, &stack, line_num);
			line_size = getline(&globalvar.line_buf, &line_buf_size,
					    globalvar.fd); }}
	m_free_dlistint(stack);
	free(globalvar.line_buf);
	globalvar.line_buf = NULL;
	fclose(globalvar.fd);
	return (EXIT_SUCCESS);
}
