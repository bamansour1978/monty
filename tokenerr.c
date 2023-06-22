#include "monty.h"

/**
 * m_array_len - calculate array of a token.
 * Return: unsigned int.
 */
unsigned int m_array_len(void)
{
	unsigned int token_len = 0;

	while (globalvar.token2[token_len])
		token_len++;
	return (token_len);
}
/**
 * m_tokerr - makes the last element of instruction as error cod.
 * @error_status: type int.
 */
void m_tokerr(int error_status)
{
	int token_len = 0, i = 0;
	char *exit_str = NULL;
	char *new_token = NULL;

	token_len = array_len();
	new_token = malloc(sizeof(char *) * (token_len + 2));
	if (!globalvar.token2)
	{
		stderr_malloc();
		return;
	}
	while (i < token_len)
	{
		new_token[i] = globalvar.token2[i];
		i++;
	}
	exit_str = get_int(error_status);
	if (!exit_str)
	{
		free(globalvar.token2);
		stderr_malloc();
		return;
	}
	free(globalvar.token2);
	globalvar.token2 = new_token;
}
