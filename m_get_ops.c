#include "monty.h"

/**
 * m_get_builtin - Parses the instruction with function.
 * @token: type pointer extern 
 * @stack: type pointer node  data struct
 * @line_number: line  instructions
 * Return: Return the funtion
 */
int m_get_builtin(char *token, stack_t **stack, unsigned int line_num)
{
	instruction_t op_built[] = {
		{ "push", m_push },
		{ "pall", m_pall},
		{ "pop", m_pop },
		{ "add", m_add },
		{ "nop", m_nop },
		{ "sub", m_sub },
		{ "pall", m_pall },
		{ "pint", m_pint },
		{ "swap", m_swap },
		{ "mul", m_mul },
		{ "div", m_div_m },
		{ "pchar", m_pchar },
		{ "mod", m_mod_m },
		{ "\n", m_nop },
		{ " ", m_nop },
		{ "\t", m_nop },
		{ "pstr", m_pstr_t },
		{ "rotl", m_rotrl },
		{ "rotr", m_rotr },
		{ NULL, NULL }
	};
	int i, flag = 0;
	char *argumentos = NULL;

	if (stack == NULL || token == NULL)
		return (0);
	argumentos = token;
	for (i = 0; op_built[i].opcode; i++)
	{
		if (strcmp(argumentos, op_built[i].opcode) == 0)
		{
			flag = 1;
			op_built[i].f(stack, line_num);
			break;
		}
	}
	if (flag == 0)
		m_stderr_unknown(token, line_num);
	return (0);
}
