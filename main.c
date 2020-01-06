#include "monty.h"

/**
 * main - Checks arguments, open file to work with then
 * calls the function _readline to extract the lines from the file
 *
 * @argc: Number of arguments passed to the program.
 * @argv: arguments, file to work with must be included.
 * Return: 0  on success,
 * otherwise calls the appropiate function to handle the error and exits.
 */
int main(int argc, char **argv)
{
	int montyfd;
	FILE *montyf;

	if (argc == 2)
	{
		montyfd = open(argv[1], O_RDONLY);
		if (montyfd == -1)
		{
			openerr(argv[1]);
		}
		montyf = fdopen(montyfd, "r");
		_readline(montyf);
		fclose(montyf);
	} else
		nargumenterr();
	return (0);
}

/**
 * _readline - Reads the lines from a file and
 * calls the function _chkcmd to call the appropiate operation
 *
 * @fd: file descriptor to a File in the system
 *
 */
void _readline(FILE *fd)
{
	char *cmd, *cvalue, *linerd = NULL, *temp = NULL;
	size_t nlinerd = 0, line = 0;
	stack_t *stack = NULL;
	instruction_t ins[] = {
		{"push", _opush},
		{"pall", _opall},
		{NULL, NULL}
	};

	while (getline(&linerd, &nlinerd, fd) > 0)
	{
		temp = linerd;
		line++;
		_trim(&temp);
		cmd = temp;
		cvalue = NULL;
		while (*temp != '\0')
		{
			if (*temp == ' ' && *temp - 1 != ' ')
			{
				*temp = '\0';
				cvalue = temp + 1;
			}
			temp += 1;
		}
		printf("temp = %p, linerd = %p\n", temp, linerd);
		_chkcmd(ins, cmd, cvalue, &stack, line);
	}
	free(linerd);
	_free_stack(stack);
}

/**
 * _chkcmd - Compares a command received and calls the appropiate function.
 *
 * @ins: Structure with a list of operations.
 * @cmd: command to compare with structure elements.
 * @cvalue: argument used when calling the operation function.
 * @stack: Linear data structure used when calling the operation function.
 * @line: Number of line working with at the moment of call
 *
 */
void _chkcmd(instruction_t *ins, char *cmd, char *cvalue,
	     stack_t **stack, size_t line)
{
	unsigned int line_number = 0;

	if (cvalue != NULL)
		line_number = _atoi(cvalue);
	while (ins->opcode != NULL)
	{
		if (_strcmp(ins->opcode, cmd) == 0)
		{
			if (_strcmp(ins->opcode, "push") == 0)
			{
				if (cvalue == NULL)
					nint(line);
			}
			ins->f(stack, line_number);
			break;
		}
		ins += 1;
	}
}
