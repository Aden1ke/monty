#include "monty.h"
/**
 * divide - divide thr first two stack
 * @stack: the stack in reference
 * @line_number: line number
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * mod - find the module of first two stack
 * @stack: the stack in reference
 * @line_number: line number
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * _rot - rotate the stack from the bottom to top
 * @stack: stack to be rotated
 * Return: void
 */
void _rot(stack_t **stack)
{
	stack_t *temp;

	if ((*stack)->next != NULL)
	{
		temp = (*stack);
		while (temp->next != NULL)
			temp = temp->next;
		(*stack)->prev = temp;
		temp->next = (*stack);
		temp->prev->next = NULL;
		temp->prev = NULL;
		(*stack) = (*stack)->prev;
	}
}
