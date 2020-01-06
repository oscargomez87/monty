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

/**
 * _nop - Does nothing.
 *
 * @stack: Linear data structure.
 * @line_number: number to push at the end of the stack.
 */
void _nop(__attribute__((unused)) stack_t **stack,
	  __attribute__((unused)) unsigned int line_number)
{
}

/**
 * _sub - Inserts an element at the end of a stack.
 *
 * @stack: Linear data structure.
 * @line_number: number to push at the end of the stack.
 */
void _sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int a, b;
	stack_t *temp;

	temp = *stack;
	if (*stack == NULL || (*stack)->prev == NULL
	    || (*stack)->prev->prev == NULL)
		emsubstackerror();
	a = (*stack)->n;
	b = (*stack)->prev->n;
	(*stack)->prev->n = b - a;
	(*stack)->prev->next = NULL;
	*stack = (*stack)->prev;
	free(temp);
}

/**
 * _div - Inserts an element at the end of a stack.
 *
 * @stack: Linear data structure.
 * @line_number: number to push at the end of the stack.
 */
void _div(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int a, b;
	stack_t *temp;

	temp = *stack;
	if (*stack == NULL || (*stack)->prev == NULL
	    || (*stack)->prev->prev == NULL)
		emdivstackerrorn0();
	a = (*stack)->n;
	if (a == 0)
		emdivstackerror0();
	b = (*stack)->prev->n;
	(*stack)->prev->n = (b / a);
	(*stack)->prev->next = NULL;
	*stack = (*stack)->prev;
	free(temp);
}
