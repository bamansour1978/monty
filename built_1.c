#include "monty.h"

/**
 * m_push - Added node to  stack
 * @stack: head  linkedlist
 * @line_num: line num of the instruction
 *
 * Return: void
 */
void m_push(stack_t **stack, unsigned int line_num)
{

	int n = 0;

	if (globalvar.token2 == NULL)
	{
		m_free_dlistint(*stack);
		m_stderr_int(line_num);
	}
	if (!m_isdigit() || stack == NULL)
	{
		m_free_dlistint(*stack);
		m_stderr_int(line_num);
	}
	n = atoi(globalvar.token2);
	if (*stack  == NULL)
	{
		m_create_node_stackfirst(stack, n);
	}
	else
	{
		m_create_node_stackend(stack, n);
	}
}

/**
 * m_pall - Print a stack
 * @stack: head  linkedlist
 * @line_num: line num of the instruction
 *
 * Return: void
 */
void m_pall(stack_t **stack, unsigned int line_num)
{

	stack_t *temp = NULL;


	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_num != 1)
	{
		m_free_dlistint(*stack);
		m_free_globalvars();
		exit(EXIT_SUCCESS);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
	printf("%d\n", temp->n);
}


/**
 * m_pint - Print  stack
 * @stack: head linkedlist
 * @line_num: line num of the instruction
 *
 * Return: void
 */
void m_pint(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		m_pint_e(line_num);
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	printf("%d", temp->n);
	printf("\n");
}

/**
 * m_swap - Print a stack
 * @stack: head linkedlist
 * @line_num: line num of the instruction
 *
 * Return: void
 */
void m_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int i, j;

	if (*stack == NULL || stack == NULL)
		m_op_e(line_num, "swap");

	temp = (*stack)->next;
	if ((*stack)->next == NULL)
		m_op_e(line_num, "swap");
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	i = temp->n;
	j = temp->prev->n;
	temp->n = j;
	temp->prev->n = i;
}
/**
 * m_nop - anything
 * @stack: head  linkedlist
 * @line_num: line num of the instruction
 *
 * Return: void
 */
void m_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
