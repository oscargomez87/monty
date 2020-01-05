/**
 * _trim - Removes extra spaces
 *
 * @linerd: pointer to address with string to remove spaces from
 */
void _trim(char **linerd)
{
	int i = 0;

	while (*(*linerd) == ' ')
		(*linerd)++;
	while (*(*linerd + i) != '\n')
		i++;
	*(*linerd + i) = '\0';
}
