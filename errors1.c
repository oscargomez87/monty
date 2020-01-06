#include "monty.h"
/**
 * emstackerror - Prints an error to stderr when malloc fails
 *
 */
void emstackerror(void)
{
	char buff[1024];

	snprintf(buff, 1024,
		 "L%lu: can't pint, stack empty\n", line);
	write(STDERR_FILENO, buff, _strlen(buff));
	exit(EXIT_FAILURE);
}

/**
 * empopstackerror - Prints an error to stderr when malloc fails
 *
 */
void empopstackerror(void)
{
	char buff[1024];

	snprintf(buff, 1024,
		 "L%lu: can't pop an empty stack\n", line);
	write(STDERR_FILENO, buff, _strlen(buff));
	exit(EXIT_FAILURE);
}
