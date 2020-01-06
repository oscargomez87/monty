#include "monty.h"

size_t line = 0;

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
	char *cmd, *cvalue, *temp = NULL, *linerd = NULL;
	int chkres = 0;
	size_t nlinerd = 0;
	stack_t *stack = NULL;

	instruction_t ins[] = {
		{"push", _opush},
		{"pall", _opall},
		{"pint", _opint},
		{"pop", _opop},
		{"swap", _oswap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (getline(&linerd, &nlinerd, fd) > 0)
	{
		temp = linerd;
		line++;
		cmd = NULL;
		cvalue = NULL;
		_trim(&temp, &cmd);
		_trim(&temp, &cvalue);
		chkres = _chkcmd(ins, cmd, cvalue, &stack);
		if (chkres == -1)
		{
			nint(line, linerd, stack, fd);
		} else if (chkres == -2)
		{
			ninstructionerr(cmd, line, linerd, stack, fd);
		}
	}
	fclose(fd);
	free(linerd);
	_free_stack(stack);
}

/**
 * _chkcmd - Compares a command received and calls the appropiate function.
 *
 * @ins: Structure with a list of operations.
 * @cmd: command to compare with structure elements.
 * @cvalue: argument used when calling the operation function
 * @stack: Linear data structure used when calling the operation function.
 * Return: returns 0 on success, -1 if value is not int and
 * -2 if operation is not found
 *
 */
int _chkcmd(instruction_t *ins, char *cmd, char *cvalue, stack_t **stack)
{
	unsigned int line_number = 0, i = 0, j = 0;

	if (cmd[0] == '\0')
		return (0);
	while (ins[i].opcode != NULL)
	{
		if (_strcmp(ins[i].opcode, cmd) == 0)
		{
			if (i == 0)
			{
				if (cvalue == NULL)
					return (-1);
				while (cvalue[j])
				{
					if (_isdigit(cvalue[j]) == 0
					    && cvalue[j] != '-')
					{
						return (-1);
						}
					j++;
				}
			}
			line_number = _atoi(cvalue);
			ins[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	return (-2);
}
