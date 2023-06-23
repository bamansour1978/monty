#include "monty.h"

/**
 * m_pop_e - pop error  for empty stacks.
 * @line_num: line number of  instructions.
 * Return: EXIT_FAILURE.
 */
void m_pop_e(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	m_free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * m_pint_e - pint error  for empty stacks.
 * @line_num: line number of  instruction.
 * Return: EXIT_FAILURE
 */
void pint_e(unsigned int line_num)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
	m_free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * m_op_e - math func error message.
 * @line_num: line number  instruction.
 * @op: Operation where  error .
 * Return: EXIT_FAILURE
 */
void m_op_e(unsigned int line_num, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_num, op);
	m_free_globalvars();
	exit(EXIT_FAILURE);
}
/**
 * m_pchar_e - phar error msg for 0 stack ; non-char val.
 * @line_num: line number of  instruction
 * @msg: error  to print.
 * Return: EXIT_FAILURE.
 */
void m_pchar_e(unsigned int line_num, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_num, msg);
	m_free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * div_e - error for / by 0.
 * @line_num: line number  the instruction.
 * Return: EXIT_FAILURE
 */
void m_div_e(unsigned int line_num)
{
	fprintf(stderr, "L%u: division by zero\n", line_num);
	m_free_globalvars();
	exit(EXIT_FAILURE);
}
