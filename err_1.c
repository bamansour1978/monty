
#include "monty.h"

int m_usage_err(void);
int m_mal_err(void);
int file_open_err(char *filename);
int unk_op_err(char *opcode, unsigned int line_n);
int int_no_err(unsigned int line_n);

/**
 * m_usage_err - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int m_usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * m_mal_err - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int m_mal_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_err - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int file_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unk_op_err - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_n: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unk_op_err(char *opcode, unsigned int line_n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_n, opcode);
	return (EXIT_FAILURE);
}

/**
 * int_no_err - Prints invalid m_push argument error messages.
 * @line_n: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int int_no_err(unsigned int line_n)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_n);
	return (EXIT_FAILURE);
}
