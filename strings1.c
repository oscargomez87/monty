/**
 * _trim - Removes extra spaces, and cuts string between words
 *
 * @temp: pointer to address with string to remove spaces from
 * @dest: pointer where cut string will be assigned to
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
