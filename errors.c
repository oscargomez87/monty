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
 * when an invalidinstruction is read
 *
 */
void ninstructionerr(void)
{
	char *nierr = "L<line_number>: unknown instruction <opcode>/n";

	write(STDERR_FILENO, nierr, _strlen(nierr));
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

void nint(size_t line)
{
	char buff[1024];

	snprintf(buff, 1024, "L%lu: usage: push integer\n", line);
	write(STDERR_FILENO, buff, _strlen(buff));
        exit(EXIT_FAILURE);
}
