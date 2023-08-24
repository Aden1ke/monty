#include "monty.h"
/**
 * push - push node into a stack
 * @stack: node representing new value added.
 * @num: value added to the stack
 */
void push(stack_t **stack, int num)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - display nodes pushed into a stack
 * @stack: node representing new value added.
 */
void pall(stack_t **stack)
{
	stack_t *current_node = *stack;

	if (*stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		while (current_node != NULL)
		{
			printf("%d\n", current_node->n);
			current_node = current_node->next;
		}
	}
}

/**
 * pop - push node into a stack
 * @stack: node representing new value added.
 * @line_number: line of the command in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current_node);
}

/**
 * add - adds the top two elements of the stack
 * @stack: stack to manipulate
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;

}
/**
 * sub - subtract the top two elements of the stack
 * @stack: stack to manipulate
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n - (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
