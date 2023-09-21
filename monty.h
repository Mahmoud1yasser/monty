#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void opn_f(char *fname);
int count_line(char *buffer, int line_number, int format);
void _read_f(FILE *);
int chr_count(FILE *);
void operting_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void stack_que(stack_t **, unsigned int);
void que_add(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void top_prnt(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swp_nod(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void dived_nod(stack_t **, unsigned int);
void mul_nod(stack_t **, unsigned int);
void nod_mod(stack_t **, unsigned int);

/*String operations*/
void chr_prnt(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void err(int err_def, ...);
void more_err(int err_def, ...);
void string_err(int err_def, ...);
void rotr(stack_t **, unsigned int);

#endif