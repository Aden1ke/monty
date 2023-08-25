#include "monty.h"
/**
 * mul - multiply the top two elements of the stack
 * @stack: stack to manipulate
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * pstr - print a string
 * @stack: node representing new value added.
 * @line_number: line of the command in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!temp)
	{
		putchar('\n');
	}
	while (temp && temp->n > 0 && temp->n <= 127)
	{
		if (temp->n == 0)
			break;
		else if (!isascii(temp->n))
			break;
		else
			putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * pchar - print a character
 * @stack: node representing new value added.
 * @line_number: line of the command in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;


	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp && temp->n > 0 && temp->n <= 127)
	{
		putchar(temp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar('\n');
}
/**
 * is_integer - checks if a string is digit
 * @str: string to check
 * Return: 1 if true and 0 if false
 */
int is_integer(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (!*str)
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
