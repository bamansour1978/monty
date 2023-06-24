#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>


/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;
	char **op_toks = NULL;

	if (argc != 2)
		return (m_usage_err());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (file_open_err(argv[1]));
	exit_code = runn_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
