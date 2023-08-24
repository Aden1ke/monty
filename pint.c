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
 * Return: void
 */
void nop(void)
{
	/* nothing to see here*/
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
	stack_t *node;
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short.\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = (*stack)->next;
	temp = node->n;
	node->n = (*stack)->n;
	(*stack)->n = temp;
}
