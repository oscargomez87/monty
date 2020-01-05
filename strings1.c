#include <stdio.h>
void _trim(char **linerd)
{
	int i = 0;

	while (*(*linerd) == ' ')
		(*linerd)++;
	while (*(*linerd + i) != '\n')
		i++;
	*(*linerd + i) = '\0';
}
