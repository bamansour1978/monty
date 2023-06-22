#include "monty.h"


/**
 * m_stderr_usage -  error.
 * Return: EXIT_FAILURE
 */
void stderr_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * m_stderr_malloc - Prints malloc error .
 * Return: EXIT_FAILURE
 */

void m_stderr_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_globalvars();
	exit(EXIT_FAILURE);
}
/**
 * m_stderr_fopen - error of fopen.
 * @filename: type pointer  of filename
 * Return: EXIT_FAILURE
 */
void m_stderr_fopen(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * m_stderr_int - error of integer.
 * @line_num: type pointer of line num
 * Return: EXIT_FAILURE
 */
void m_stderr_int(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * m_stderr_unknown - unknown error .
 * @line_num: line number of instruction.
 * @token: type pointer char of instruction.
 * Return: EXIT_FAILURE
 */
void m_stderr_unknown(char *token, unsigned int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, token);
	free_globalvars();
	exit(EXIT_FAILURE);
}
