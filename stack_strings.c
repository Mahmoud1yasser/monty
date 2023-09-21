#include "monty.h"

/**
 * print_char - Prints the Ascii
 *
 * @stack: Pointer to a pointer
 *
 * @line_number: Interger represent
*/

void print_char(stack_t **stack, unsigned int line_number)
{
	int as;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	as = (*stack)->n;
	if (as < 0 || as > 127)
		string_err(10, line_number);
	printf("%c\n", as);
}

/**
 * print_str - Prints a string.
 *
 * @stack: Pointer to a point
 *
 * @ln: Interger represent
*/

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ac;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ac = temp->n;
		if (ac <= 0 || ac > 127)
			break;
		printf("%c", ac);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node
 *
 * @stack: Pointer to a pointer
 *
 * @ln: Interger represent
*/

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node
 *
 * @stack: Pointer to a pointer
 *
 * @ln: Interger represent
*/

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
