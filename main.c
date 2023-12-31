#include "monty.h"
/**
 * main - a program that implements stacks and
 * queues using monty
 * @ac: number of arguments
 * @args: arguments inputed.
 * Return: 0.
 */
int main(int ac, char *args[])
{
	FILE *file;
	stack_t *stack;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(args[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s \n", args[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	parse_file(file, &stack);
	fclose(file);

	return (0);
}
/**
 * parse_file - a function that prints the
 * number of arguments passed into it.
 * @file: file to open.
 * @stack: linked list.
 */
void parse_file(FILE *file, stack_t **stack)
{
	size_t length = 0;
	int line_num = 0;
	char *buffer_line = NULL, *opcode;

	while (getline(&buffer_line, &length, file) != -1)
	{
		line_num++;
		if (buffer_line[0] == '#')
			continue;
		opcode = strtok(buffer_line, " \t\n$");
		if (opcode == NULL || strlen(opcode) == 0)
		{
			continue;
		}

		execute_command(opcode, line_num, buffer_line, stack);
	}

	free(buffer_line);
	free_stack(*stack);
}

/**
 * parse_push - a function that implement push
 * and checks if value given is a number
 * @buffer_line: line to read command from.
 * @line_num: the line at which the command is found it the file.
 * @stack: node used.
 */
void parse_push(char *buffer_line, int line_num, stack_t **stack)
{
	int val;
	char *val_str = strtok(NULL, " \t\n$");

	if (val_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free(buffer_line);
		exit(EXIT_FAILURE);
	}
	if (!is_integer(val_str))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free(buffer_line);
		exit(EXIT_FAILURE);
	}
	val = atoi(val_str);
	push(stack, val);
	(void)val;
}

/**
 * unknown_instruction - function that handles unknown command.
 * @opcode: command.
 * @line_num: the line at which the command
 * is found it the file.
 * @buffer_line: line to read command from.
 */
void unknown_instruction(char *opcode, int line_num, char *buffer_line)
{
	fprintf(stderr, "L%d: unknown instruction %s \n", line_num, opcode);
	free(buffer_line);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - free a linked list
 * @stack: node to free
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;

		if (temp != NULL)
			free(temp);
	}
}
