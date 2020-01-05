/**
 * _atoi - convert string to integer
 * @s: string to convert
 * Return: integer
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int n = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = sign * -1;
		} else if (s[i] >= 0 + '0' && s[i] <= 9 + '0')
		{
			n = n * 10 + s[i] - '0';
		} else if (s[i - 1] >= 0 + '0' && s[i - 1] <= 9 + '0')
			break;
		i++;
	}
	return (sign * n);
}

/**
 * _strlen - Returns the length of a string
 * @s: pointer to char array
 * Return: size of array
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != 0)
		i++;
	return (i);
}

/**
 * _strcmp - compare strings
 * @s1: main string to compare
 * @s2: string to compare with s1
 * Return: 1 if s1 is greater than s2, -1 if s1 is less than s1 and 0 if s1
 * matches s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0, n = 1;

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (i == j)
	{
		for (i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] == s2[i])
				n = 0;
			else
			{
				n++;
				break;
			}
		}
	} else
		n = (i < j ? j - i : j - i);
	return (n);
}

/**
 * _strncat - Concatenates 2 strings a n number of bytes
 * @dest: Concatenated string destination
 * @src: string source
 * @n: number of bytes to concatenate
 * Return: pointer to resulting string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j;

	while (*(dest + i))
	{
		i++;
	}
	for (j = 0; j < n; j++, i++)
	{
		*(dest + i) = *(src + j);
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: digit to evaluate
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	int i;

	if (c >= 48 && c <= 57)
		i = 1;
	else
		i = 0;
	return (i);
}
