#include "monty.h"

void m_push(stack_t **stack, unsigned int line_n);
void m_push(stack_t **stack, unsigned int line_n);
void m_pint(stack_t **stack, unsigned int line_n);
void m_pop(stack_t **stack, unsigned int line_n);
void m_swap(stack_t **stack, unsigned int line_n);

/**
 * m_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_push(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_token_errors(m_mal_err());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_token_errors(int_no_err(line_n));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_token_errors(int_no_err(line_n));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (mode_chek(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * m_push - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_push(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_n;
}

/**
 * m_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_pint(stack_t **stack, unsigned int line_n)
{
	if ((*stack)->next == NULL)
	{
		set_op_token_errors(pint_m_err(line_n));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * m_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_pop(stack_t **stack, unsigned int line_n)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_token_errors(m_po_err(line_n));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * m_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_n: The current working line number of a Monty bytecodes file.
 */
void m_swap(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_token_errors(err_stack_short(line_n, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
