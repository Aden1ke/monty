#include "monty.h"
/**
 * execute_command - a function that compares command
 * and checks if value given is a number
 * @buffer: line to read command from buffer.
 * @line_num: the line at which the command is found it the file.
 * @stack: node used.
 * @opcode: command to compare
 */
void execute_command(char *opcode, int line_num, char *buffer, stack_t **stack)
{
	if (strcmp(opcode, "push") == 0)
		parse_push(buffer, line_num, stack);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_num);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_num);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_num);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_num);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_num);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line_num);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(stack, line_num);
	else if (strcmp(opcode, "_rot") == 0)
                _rot(stack);
	else if (strcmp(opcode, "mod") == 0)
                mod(stack, line_num);
	 else if (strcmp(opcode, "divide") == 0)
                divide(stack, line_num);
	else
		unknown_instruction(opcode, line_num, buffer);
}
