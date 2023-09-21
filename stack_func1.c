#include "monty.h"


/**
 * stack_que - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void stack_que(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *pntr;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	pntr = head;
	head = *new_node;
	head->next = pntr;
	pntr->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *pntr;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	pntr = *stack;
	while (pntr != NULL)
	{
		printf("%d\n", pntr->n);
		pntr = pntr->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *pntr;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	pntr = *stack;
	*stack = pntr->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(pntr);
}

/**
 * top_prnt - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void top_prnt(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
