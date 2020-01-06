#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern size_t line;

/*
 * String manipulation functions
 */
int _strlen(char *);
char *_strncat(char *, char *, int);
int _strcmp(char *, char *);
int _atoi(char *);
int _isdigit(int);
void _trim(char **, char **);

int _abs(int);

/*
 * Error handling functions
 */
void openerr(char *);
void nargumenterr(void);
void merror(void);
void nint(size_t, char *, stack_t *, FILE *);
void ninstructionerr(char *, size_t, char *, stack_t *, FILE *);
void emstackerror(void);
void empopstackerror(void);
void emswapstackerror(void);
void emaddstackerror(void);
void emsubstackerror(void);

/*
 * Core functions, first steps to operations call
 */
void _readline(FILE *);
int _chkcmd(instruction_t *, char *, char *, stack_t **);

/*
 * Operations over stack functions
 */
void _opush(stack_t **, unsigned int);
void _opint(stack_t **, unsigned int);
void _opop(stack_t **, unsigned int);
void _oswap(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _opall(stack_t **, unsigned int);
void _free_stack(stack_t *);

#endif
