#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/*system status*/
int status;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*project function*/
void unknown_instruction(char *opcode, int line_num, char *buffer_line);
void parse_push(char *buffer_line, int line_num, stack_t **stack);
void parse_file(FILE *file, stack_t **stack);
void pall(stack_t **stack);
void push(stack_t **stack, int num);
void pint(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void nop(stack_t **stack);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
#endif
