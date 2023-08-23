#include "monty.h"
/**
 * pint - print the top of the stack
 * @stack: stack to be printed
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL || *stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
