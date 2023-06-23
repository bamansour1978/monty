#include "monty.h"

/**
 * m_create_node_stack - creat a node .
 * @stack: A pointer  and stack.
 * Return: EXIT SUCCESS
 */
int m_create_node_stack(stack_t **stack)
{
	stack_t *p;

	p = malloc(sizeof(stack_t));
	if (p == NULL)
		m_stderr_malloc();
	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return (EXIT_SUCCESS);
}
/**
 * m_free_node_stack - Free  stack_t .
 * @stack: A pointer .
 */
void m_free_node_stack(stack_t **stack)
{
	stack_t *temp_node = *stack;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
}
/**
 * m_check_opcode - checks  .
 * @stack: A pointer .
 * Return: The value  Stack or Queue
 */
int m_check_opcode(stack_t *stack)
{
	int ret_val = 2;

	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (ret_val);
}
