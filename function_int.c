#include "main.h"
/**
 *print_int - called from _printf
 *@spec_arg: int
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 *Return: int
 */
int print_int(va_list spec_arg, indi *d)
{
	int n = va_arg(spec_arg, int);
	int res = count_num(n);

	if (d->space == 1 && d->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (d->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	print_number(n);
	return (res);
}

/**
 * count_num - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_num(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}
