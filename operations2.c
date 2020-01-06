#include "monty.h"

/**
 * _div - Inserts an element at the end of a stack.
 *
 * @stack: Linear data structure.
 * @line_number: number to push at the end of the stack.
 */
void _mul(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int a, b;
	stack_t *temp;

	temp = *stack;
	if (*stack == NULL)
		emmulstackerror();
	if ((*stack)->prev == NULL || (*stack)->prev->prev == NULL)
		emmulstackerror();
	a = (*stack)->n;
	b = (*stack)->prev->n;
	(*stack)->prev->n = (b * a);
	(*stack)->prev->next = NULL;
	*stack = (*stack)->prev;
	free(temp);
}
