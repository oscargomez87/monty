/**
 * _trim - Removes extra spaces
 *
 * @linerd: pointer to address with string to remove spaces from
 */
void _trim(char **temp, __attribute__((unused)) char **dest)
{
	while (*(*temp) == ' ')
		(*temp)++;
	*dest = *temp;
	while (*(*temp) != '\0')
	{
		if ((*(*temp) == ' ' && *(*temp) - 1 != ' ') || *(*temp) == '\n')
		{
			*(*temp) = '\0';
			*temp += 1;
			break;
		}
		*temp += 1;
	}
}
