/*
 * File: monty_funcs_2.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

void m_add(stack_t **stack, unsigned int line_n);
void m_sub(stack_t **stack, unsigned int line_n);
void m_div(stack_t **stack, unsigned int line_n);
void m_mul(stack_t **stack, unsigned int line_n);
void m_mod(stack_t **stack, unsigned int line_n);

/**
 * m_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void m_add(stack_t **stack, unsigned int line_n)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_token_errors(err_stack_short(line_n, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	m_pop(stack, line_n);
}

/**
 * m_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void m_sub(stack_t **stack, unsigned int line_n)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_token_errors(err_stack_short(line_n, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	m_pop(stack, line_n);
}

/**
 * m_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void m_div(stack_t **stack, unsigned int line_n)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_token_errors(err_stack_short(line_n, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_token_errors(err_m_div(line_n));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	m_pop(stack, line_n);
}

/**
 * m_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void m_mul(stack_t **stack, unsigned int line_n)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_token_errors(err_stack_short(line_n, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	m_pop(stack, line_n);
}

/**
 * m_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void m_mod(stack_t **stack, unsigned int line_n)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_token_errors(err_stack_short(line_n, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_token_errors(err_m_div(line_n));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	m_pop(stack, line_n);
}
