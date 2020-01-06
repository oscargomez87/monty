#include "monty.h"

/**
 * emdivstackerrorn0 - Prints an error to stderr when malloc fails
 *
 */
void emdivstackerrorn0(void)
{
	char buff[1024];

	snprintf(buff, 1024,
		 "L%lu: can't div, stack too short\n", line);
	write(STDERR_FILENO, buff, _strlen(buff));
	exit(EXIT_FAILURE);
}

/**
 * emdivstackerror0 - Prints an error to stderr when malloc fails
 *
 */
void emdivstackerror0(void)
{
	char buff[1024];

	snprintf(buff, 1024,
		 "L%lu: division by zero\n", line);
	write(STDERR_FILENO, buff, _strlen(buff));
	exit(EXIT_FAILURE);
}

/**
 * emmulstackerror - Prints an error to stderr when malloc fails
 *
 */
void emmulstackerror(void)
{
	char buff[1024];

	snprintf(buff, 1024,
		 "L%lu: can't mul, stack too short\n", line);
	write(STDERR_FILENO, buff, _strlen(buff));
	exit(EXIT_FAILURE);
}

