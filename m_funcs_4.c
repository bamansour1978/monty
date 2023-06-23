#include "monty.h"

void m_rotl(stack_t **stack, unsigned int line_n);
void m_rotr(stack_t **stack, unsigned int line_n);
void m_stack(stack_t **stack, unsigned int line_n);
void m_queue(stack_t **stack, unsigned int line_n);

/**
 * m_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_rotl(stack_t **stack, unsigned int line_n)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_n;
}

/**
 * m_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_rotr(stack_t **stack, unsigned int line_n)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_n;
}

/**
 * m_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_stack(stack_t **stack, unsigned int line_n)
{
	(*stack)->n = STACK;
	(void)line_n;
}

/**
 * m_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_queue(stack_t **stack, unsigned int line_n)
{
	(*stack)->n = QUEUE;
	(void)line_n;
}
