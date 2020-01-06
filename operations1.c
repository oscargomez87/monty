#include "monty.h"

/**
 * _oswap - Inserts an element at the end of a stack.
 *
 * @stack: Linear data structure.
 * @line_number: number to push at the end of the stack.
 */
void _oswap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if ((*stack == NULL) || ((*stack)->prev == NULL)
	    || ((*stack)->prev->prev == NULL))
		emswapstackerror();
	temp = (*stack)->prev->prev;
	(*stack)->next = temp->next;
	temp->next = *stack;
	(*stack)->prev->prev = *stack;
	(*stack)->prev = temp;
	(*stack)->prev->next =  NULL;
	*stack = (*stack)->next;
}

/**
 * _add - Inserts an element at the end of a stack.
 *
 * @stack: Linear data structure.
 * @line_number: number to push at the end of the stack.
 */
void _add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->prev == NULL
	    || (*stack)->prev->prev == NULL)
		emaddstackerror();
	a = (*stack)->n;
	b = (*stack)->prev->n;
	(*stack)->prev->n = a + b;
	(*stack)->prev->next = NULL;
	*stack = (*stack)->prev;
}
