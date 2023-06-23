/*
 * File: errors_2.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

int err_stack_short(unsigned int line_n, char *op);
int err_m_div(unsigned int line_n);
int m_po_err(unsigned int line_n);
int err_m_div(unsigned int line_n);
int err_pchar(unsigned int line_n, char *message);

/**
 * m_po_err - Prints pop error messages for empty stacks.
 * @line_n: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int m_po_err(unsigned int line_n)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_n);
	return (EXIT_FAILURE);
}

/**
 * pint_m_err - Prints pint error messages for empty stacks.
 * @line_n: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_m_err(unsigned int line_n)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
	return (EXIT_FAILURE);
}

/**
 * err_stack_short - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_n: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_stack_short(unsigned int line_n, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_n, op);
	return (EXIT_FAILURE);
}

/**
 * err_m_div - Prints division error messages for division by 0.
 * @line_n: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_m_div(unsigned int line_n)
{
	fprintf(stderr, "L%u: division by zero\n", line_n);
	return (EXIT_FAILURE);
}

/**
 * err_pchar - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_n: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_pchar(unsigned int line_n, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_n, message);
	return (EXIT_FAILURE);
}
