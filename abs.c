/**
 * _abs - computes the absolute value of an integer
 * @n: any integer value
 * Return: 1 and prints + if n is greater than zero
 * 0 and prints 0 if n is zero
 * -1 and prints - if n is less than zero
 */
int _abs(int n)
{
	int abs = n;

	if (abs < 0)
		abs = abs * (-1);
	return (abs);
}
