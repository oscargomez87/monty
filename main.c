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
	int chkres = 0, line_number = 0;
	size_t nlinerd = 0;
	stack_t *stack = NULL;

	while (getline(&linerd, &nlinerd, fd) > 0)
	{
		temp = linerd;
		line++;
		cmd = NULL;
		cvalue = NULL;
		_trim(&temp, &cmd);
		_trim(&temp, &cvalue);
		if (_strcmp(cmd, "push") == 0)
			chkres = _chkcvalue(cvalue, &line_number);
		if (chkres == -1)
			nint(line, linerd, stack, fd);
		chkres = _chkcmd(cmd, &stack, line_number);
		if (chkres == -1)
			ninstructionerr(cmd, line, linerd, stack, fd);
	}
	fclose(fd);
	free(linerd);
	_free_stack(stack);
}

/**
 * _chkcmd - Initializes structure with pointer to functions,
 * then calls a chkop to call the appropiate function.
 *
 * @cmd: command to compare with structure elements.
 * @line_number: Data to add in the stack
 * @stack: Linear data structure used when calling the operation function.
 * Return: 0 on success, -1 if value is not int and
 * -2 if operation is not found
 *
 */
int _chkcmd(char *cmd, stack_t **stack, int line_number)
{
	void (*ptr)(stack_t **, unsigned int);
	instruction_t ins[] = {
		{"push", _opush},
		{"pall", _opall},
		{"pint", _opint},
		{"pop", _opop},
		{"swap", _oswap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	if (cmd[0] == '\0')
		return (0);
	ptr = _opchk(ins, cmd);
	if (ptr == NULL)
		return (-1);
	ptr(stack, (unsigned int)line_number);
	return (0);
}

/**
 * _opchk - Checks if the opcode asked exist.
 *
 * @ins: Structure with a list of operations.
 * @cmd: command to compare with structure elements.
 * Return: pointer to function when succesful, null otherwise
 *
 */
void (*_opchk(instruction_t *ins, char *cmd))(stack_t **, unsigned int)
{
	while (ins->opcode != NULL)
	{
		if (_strcmp(ins->opcode, cmd) == 0)
		{
			return (ins->f);
		}
		ins++;
	}
	return (NULL);
}

/**
 * _chkcvalue - Checks if a string can be converted to in, and if parses it.
 *
 * @cvalue: String to check.
 * @line_number: pointer to int used to store the cvalue parsed
 * Return: 0 if successful, -1 otherwise
 *
 */
int _chkcvalue(char *cvalue, int *line_number)
{
	int i = 0;

	if (cvalue == NULL || *cvalue == '\0')
		return (-1);
	while (*(cvalue + i))
	{
		if (_isdigit(*(cvalue + i)) == 0
		    && *(cvalue + i) != '-')
		{
			return (-1);
		}
		i++;
	}
	*line_number = _atoi(cvalue);
	return (0);
}
