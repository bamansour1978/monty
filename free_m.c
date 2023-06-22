#include "monty.h"

/**
 * m_free_dlistint - free a dlistint_t list.
 * @stack: pointer first element of the list
 * Return: no value
 */
void m_free_dlistint(stack_t *stack)
{
	stack_t *aux = NULL;
	stack_t *temp = NULL;

	temp = stack;
	while (temp != NULL)
	{
		aux = temp->next;
		free(temp);
		temp = aux;
	}
	stack = NULL;
}

/**
 * m_free_globalvars - free a dlistint_t list.
 *
 * Return: no value
 */
void m_free_globalvars(void)
{
	fclose(globalvar.fd);
	free(globalvar.line_buf);
}
