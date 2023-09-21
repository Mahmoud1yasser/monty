#include "monty.h"

/**
 * open_file - opens a file
 *
 * @file_name: the file path
 *
 * Return: void
*/

void open_file(char *file_name)
{
	FILE *fdis = fopen(file_name, "r");

	if (file_name == NULL || fdis == NULL)
		err(2, file_name);

	read_file(fdis);
	fclose(fdis);
}


/**
 * read_file - reads a file
 *
 * @fd: pointer to file descriptor
 *
 * Return: void
*/

void read_file(FILE *fd)
{
	int line_n, format = 0;
	char *buf = NULL;
	size_t l = 0;

	for (line_n = 1; getline(&buf, &l, fd) != -1; line_n++)
	{
		format = parse_line(buf, line_n, format);
	}
	free(buf);
}


/**
 * parse_line - Separates each line
 *
 * @buffer: line file
 *
 * @line_number: line number
 *
 * @format:  storage format. If 0 Nodes
 *
 * Return: Returns 0 if stack. 1 if queue.
*/

int parse_line(char *buffer, int line_number, int format)
{
	char *op, *val;
	const char *deli = "\n ";

	if (buffer == NULL)
		err(4);

	op = strtok(buffer, deli);
	if (op == NULL)
		return (format);
	val = strtok(NULL, del);

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	find_func(op, val, line_number, format);
	return (format);
}

/**
 * find_func - find the appropriate function
 *
 * @opcode: opcode
 *
 * @value: argument of opcode
 *
 * @format:  storage format. If 0 Nodes
 *
 * @ln: line number
 *
 * Return: void
*/

void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int f;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			f = 0;
		}
	}
	if (f == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls
 *
 * @func: Pointer
 *
 * @op: string
 *
 * @val: string representing a numeric value.
 *
 * @ln: line numeber for the instruction.
 *
 * @format: Format specifier. If 0 Nodes
*/

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int fl;
	int i;

	fl = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fl = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * fl);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
