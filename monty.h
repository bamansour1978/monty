#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_n);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void m_free_stack(stack_t **stack);
int m_init_stack(stack_t **stack);
int mode_chek(stack_t *stack);
void fr_token(void);
unsigned int token_array_lengh(void);
int runn_monty(FILE *script_fd);
void set_op_token_errors(int error_code);

/* OPCODE FUNCTIONS */
void m_push(stack_t **stack, unsigned int line_n);
void m_push(stack_t **stack, unsigned int line_n);
void m_pint(stack_t **stack, unsigned int line_n);
void m_pop(stack_t **stack, unsigned int line_n);
void m_swap(stack_t **stack, unsigned int line_n);
void m_add(stack_t **stack, unsigned int line_n);
void m_nop(stack_t **stack, unsigned int line_n);
void m_sub(stack_t **stack, unsigned int line_n);
void m_div(stack_t **stack, unsigned int line_n);
void m_mul(stack_t **stack, unsigned int line_n);
void m_mod(stack_t **stack, unsigned int line_n);
void m_pchar(stack_t **stack, unsigned int line_n);
void m_pstr(stack_t **stack, unsigned int line_n);
void m_rotl(stack_t **stack, unsigned int line_n);
void m_rotr(stack_t **stack, unsigned int line_n);
void m_stack(stack_t **stack, unsigned int line_n);
void m_queue(stack_t **stack, unsigned int line_n);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int m_usage_err(void);
int m_mal_err(void);
int file_open_err(char *filename);
int unk_op_err(char *opcode, unsigned int line_n);
int int_no_err(unsigned int line_n);
int m_po_err(unsigned int line_n);
int pint_error(unsigned int line_n);
int short_stack_error(unsigned int line_n, char *op);
int div_error(unsigned int line_n);
int pchar_error(unsigned int line_n, char *message);

#endif /* __MONTY_H__ */
