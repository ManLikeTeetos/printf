#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - called from _printf
 * @spec_arg: char
 * Return: int
 */
int print_char(va_list spec_arg)
{
	char c;

	c = va_arg(spec_arg, int);
	_putchar(c);
	return (1);
}
/**
 * print_string - called from _printf
 * @spec_arg: string
 * Return: int
 */
int print_string(va_list spec_arg)
{
	char *s;
	int i;

	s = va_arg(spec_arg, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

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
 * * @f: pointer to the struct that determines
 * * if a flag is passed to _printf
 * * Description: the function calls convert() which in turns converts the input
 * * number into the correct base and returns it as a string
 * * Return: the number of char printed
 */
int print_binary(va_list spec_arg)
{
	unsigned int num = va_arg(spec_arg, unsigned int);
	char *str = spec_convert(num, 2, 0);

	return (_puts(str));
}
