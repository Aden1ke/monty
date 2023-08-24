#include "monty.h"
/**
 * pint - print the top of the stack
 * @stack: stack to be printed
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL && *stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * nop - does nothing
 * @stack: stack in reference
 * Return: void
 */
void nop(stack_t **stack)
{
	/* nothing to see here*/
	(void) stack;
}
/**
 * swap - swap two elements in a stack
 * @stack: stack in reference
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short.\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
