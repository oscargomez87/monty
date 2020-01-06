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

	temp = (*stack)->prev->prev;
	(*stack)->next = temp->next;
	temp->next = *stack;
	(*stack)->prev->prev = *stack;
	(*stack)->prev = temp;
	(*stack)->prev->next =  NULL;
	*stack = (*stack)->next;
}
