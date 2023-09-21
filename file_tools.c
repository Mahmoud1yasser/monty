#include "monty.h"

/**
 * open_file - opens a file
 *
 * @file_name: the file namepath
 *
 * Return: void
*/

void open_file(char *file_name)
{
	FILE *fdes = fopen(file_name, "r");

	if (file_name == NULL || fdes == NULL)
		err(2, file_name);

	read_file(fdes);
	fclose(fdes);
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
 * @buffer: line from the file
 *
 * @line_number: line number
 *
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 *
 * Return: Returns 0 if the opcode is stack. 1 if queue.
*/

int parse_line(char *buffer, int line_number, int format)
{
	char *op, *val;
	const char *del = "\n ";

	if (buffer == NULL)
		err(4);

	op = strtok(buffer, del);
	if (op == NULL)
		return (format);
	val = strtok(NULL, del);

	if (strcmp(opc, "stack") == 0)
		return (0);
	if (strcmp(opc, "queue") == 0)
		return (1);

	find_func(op, val, line_num, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

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

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
