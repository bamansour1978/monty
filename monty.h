#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


#define QUEUE 1
#define STACK 0
#define DELIM " \n\t\a\b"

/**
 * globales_s - struct variable globals
 * @token2: int
 * @fd: points to the previous element
 * @line_buf: points to the next element 
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO 
 */
typedef struct globales_s
{
	char *token2;
	FILE *fd;
	char *line_buf;

} globales_t;

extern globales_t globalvar;

/**
 * struct stack_s - doubly linked list representation 
 * @n: integer
 * @prev: points to the previous element
 * @next: points to the next element 
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO 
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

/* main.c */
int main(int argc, char **argv);

/* node functions */
stack_t *m_create_node_stackfirst(stack_t **stack, int n);
stack_t *m_create_node_stackend(stack_t **stack, int n);
void m_free_node_stack(stack_t **stack);

/* get_builtin */
int m_get_builtin(char *token, stack_t **stack, unsigned int line_num);
/* builtins functions */
void m_push(stack_t **stack, unsigned int line_num);
void m_pall(stack_t **stack, unsigned int line_num);
void m_pop(stack_t **stack, unsigned int line_num);
void m_add(stack_t **stack, unsigned int line_num);
void m_nop(stack_t **stack, unsigned int line_num);
void m_sub(stack_t **stack, unsigned int line_num);
void m_pint(stack_t **stack, unsigned int line_num);
void m_swap(stack_t **stack, unsigned int line_num);
void m_pchar(stack_t **stack, unsigned int line_num);
void m_mul(stack_t **stack, unsigned int line_num);
void m_div_m(stack_t **stack, unsigned int line_num);
void m_mod_m(stack_t **stack, unsigned int line_num);
void m_pstr_t(stack_t **stack, unsigned int line_num);
void m_rotrl(stack_t **stack, unsigned int line_num);





/*error*/
void m_stderr_usage(void);
void m_stderr_malloc(void);
void m_stderr_fopen(char *fd);
void m_stderr_int(unsigned int line_num);
void m_stderr_unknown(char *token, unsigned int line_num);
void m_div_e(unsigned int line_num);
void m_op_e(unsigned int line_num, char *op);
/* TEST F */

void m_tokerr(int error_code);
unsigned int m_array_len(void);
char *m_get_int(int num);
unsigned int m_abs_m(int);
int m_len_buff_uint(unsigned int num, unsigned int base);
void m_full_buff(unsigned int num, unsigned int base, char *buff, int buff_size);
void m_pop_e(unsigned int line_num);
void m_pint_e(unsigned int line_num);
void m_pchar_e(unsigned int line_num, char *msg);
int m_isdigit();
void m_free_dlistint(stack_t *stack);
void m_free_globalvars(void);
void m_rotr(stack_t **stack, unsigned int line_num);
stack_t *m_add_dnodeint(stack_t **head, int n);




#endif
