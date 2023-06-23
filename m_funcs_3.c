#include "monty.h"

void m_nop(stack_t **stack, unsigned int line_n);
void m_pchar(stack_t **stack, unsigned int line_n);
void m_pstr(stack_t **stack, unsigned int line_n);

/**
 * m_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_nop(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}

/**
 * m_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_pchar(stack_t **stack, unsigned int line_n)
{
	if ((*stack)->next == NULL)
	{
		set_op_token_errors(err_pchar(line_n, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_token_errors(err_pchar(line_n,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * m_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_pstr(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_n;
}
