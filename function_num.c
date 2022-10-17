#include "main.h"
/**
 *print_int - called from _printf
 *@spec_arg: int
 *Return: int
 */
int print_int(va_list spec_arg)
{
	long n = va_arg(spec_arg, int), i = 0, j, length = 0;
	int arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
		length++;
	}
	if (n == 0)
	{
		_putchar('0');
		length++;
	}
	while (n != 0)
	{
		arr[i] = n % 10;
		n = n / 10;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(arr[j] + '0');
	}
	length += i;
	return (length);
}

/**
 *  * print_binary - prints a number in base 2
 *   * @spec_arg: va_list arguments from _printf
 * * if a flag is passed to _printf
 * Description: the function calls convert()
 * which in turns converts the input
 * * number into the correct base and returns it as a string
 * * Return: the number of char printed
 */
int print_binary(va_list spec_arg)
{
	unsigned int num = va_arg(spec_arg, unsigned int);
	char *str = spec_convert(num, 2, 0);

	return (_puts(str));
}
