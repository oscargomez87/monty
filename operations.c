#include "monty.h"

/**
 * _opush - Inserts an element at the end of a stack.
 *
 * @stack: Linear data structure.
 * @line_number: number to push at the end of the stack.
 */
void _opush(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		merror();
	new->n = line_number;
	new->next = NULL;
	new->prev = *stack;
	*stack = new;
}

/**
 * _opint - Inserts an element at the end of a stack.
 *
 * @stack: Linear data structure.
 * @line_number: unused.
 */
void _opint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
                return;
        temp = *stack;
        while (temp->next != NULL)
        {
                temp = temp->next;
        }
	printf("%d\n", temp->n);
}

/**
 * _opall - Prints all the elements of a stack
 *
 * @stack: Linear data structure.
 * @line_number: unused.
 */
void _opall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * _free_stack - releases memory used by the program
 *
 * @stack: stack to release memory used from
 *
 */
void _free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;
	while (stack)
	{
		temp = stack->prev;
		free(stack);
		stack = temp;
	}
}
