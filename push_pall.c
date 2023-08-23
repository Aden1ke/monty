#include "monty.h"
/**
 * push - push node into a stack
 * @added_node: node representing new value added.
 * @num: value added to the stack
 * Return: number of nodes.
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
	else
		*stack = new_node;
}
void pall(stack_t **stack)
{
	stack_t *current_node = *stack;

	if (*stack == NULL)
	{
		printf("stack is empty\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (current_node->next != NULL)
			current_node = current_node->next;
		while (current_node != NULL)
		{
			printf("%d\n", current_node->n);
			current_node = current_node->prev;
		}
	}
}
