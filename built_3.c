#include "monty.h"

/**
 * m_div_m - divs 2d top node by  top element of the stack.
 * @stack: head  linkedlist
 * @line_num: line number of  instruction
 */
void m_div_m(stack_t **stack, unsigned int line_num)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		m_op_e(line_num, "div");
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		m_free_dlistint(*stack), m_op_e(line_num, "div");
	else
	{
		if (temp->n == 0)
			m_div_e(line_num);
		temp2->n = temp2->n / temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}



}
/**
 * m_mod_m - mod 2d top node by  top element of the stack.
 * @stack: head  linkedlist
 * @line_num: line number of instruction
 */
void m_mod_m(stack_t **stack, unsigned int line_num)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		m_op_e(line_num, "mod");
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		m_free_dlistint(*stack), m_op_e(line_num, "mod");
	else
	{
		if (temp->n == 0)
			m_div_e(line_num);
		temp2->n = temp2->n % temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}

/**
 * m_pstr_t - prints the string starting at  top of  stack
 * @stack: head linkedlist
 * @line_num: line number of  instruction
 */
void pstr_t(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	(void)line_num;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		m_free_globalvars();
		exit(0);
	}
	temp = *stack;
	if (temp->next == NULL && line_num == 2 && (temp->n < 0 || temp->n >= 127))
	{
		printf("\n");
		m_free_dlistint(*stack);
		m_free_globalvars();
		exit(0);
	}
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		if (temp->n > 0 && temp->n < 127)
		{
			printf("%c", temp->n);
			temp = temp->prev;
		}
		else
			temp = temp->prev;
		if (temp->n <= 0 || temp->n >= 127)
		{
			printf("\n");
			return;
		}
	}
	printf("%c\n", temp->n);
}
/**
 * m_rotrl - rotate to left
 * @stack: head  linkedlist
 * @line_num: line num of instruction
 */
void m_rotrl(stack_t **stack, unsigned int line_num)
{

	stack_t *temp2 = NULL;
	stack_t *temp = NULL;
	(void)line_num;

	if (*stack == NULL || ((*stack)->next == NULL))
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp2 = temp->prev;
	temp2->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
/**
 * m_rotr - rotate to left
 * @stack: head  linkedlist
 * @line_num: line num of  instruction
 */
void m_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp2 = NULL;
	(void)line_num;

	if (*stack == NULL)
		return;
	temp2 = *stack;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = *stack;
	(*stack)->prev = temp2;
	temp2 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp2;
	(*stack)->prev = NULL;
}
