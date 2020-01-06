#include "monty.h"

/**
 * openerr - Prints an error to stderr when the monty file can't be opened
 *
 * @filename: Name of the filed that couldn't be opened
 */
void openerr(char *filename)
{
	char noargerr[1024] = "\0";

	_strncat(noargerr, "Error: Can't open file ", 23);
	_strncat(noargerr, filename, _strlen(filename));
	_strncat(noargerr, "\n", 1);
	write(STDERR_FILENO, noargerr, _strlen(noargerr));
	exit(EXIT_FAILURE);
}

/**
 * nargumenterr - Prints an error to stderr when no arguments
 * or more arguments than needed are given
 *
 */
void nargumenterr(void)
{
	char *nargerr = "USAGE: monty file\n";

	write(STDERR_FILENO, nargerr, _strlen(nargerr));
	exit(EXIT_FAILURE);
}

/**
 * ninstructionerr - Prints an error to stderr
 * when an invalidinstruction is read and releases the memory used
 *
 * @opcode: Operation not found.
 * @line: Line where the wrong value is
 * @linerd: var to release memory used
 * @stack: var to release memory used
 * @fd: var to release memory used
 *
 */
void ninstructionerr(char *opcode, size_t line, char *linerd,
		     stack_t *stack, FILE *fd)
{
	char buff[1024];

	snprintf(buff, 1024, "L%lu: unknown instruction %s\n", line, opcode);
	write(STDERR_FILENO, buff, _strlen(buff));
	free(linerd);
	_free_stack(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}

/**
 * merror - Prints an error to stderr when malloc fails
 *
 */
void merror(void)
{
	char *merrmsg = "Error: malloc failed/n";

	write(STDERR_FILENO, merrmsg, _strlen(merrmsg));
	exit(EXIT_FAILURE);
}

/**
 * nint - Prints an error to stderr when
 * the value of the operation is not an integer
 *
 * @line: Line where the wrong value is
 * @linerd: var to release memory used
 * @stack: var to release memory used
 * @fd: var to release memory used
 *
 */
void nint(size_t line, char *linerd, stack_t *stack, FILE *fd)
{
	char buff[1024];

	snprintf(buff, 1024, "L%lu: usage: push integer\n", line);
	write(STDERR_FILENO, buff, _strlen(buff));
	free(linerd);
	_free_stack(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
