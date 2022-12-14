#include "main.h"
/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @spec_arg: va_list arguments from _printf
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_bigS(va_list spec_arg, indi *d)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(spec_arg, char *);

	(void)d;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = spec_convert(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}
/**
 *  * print_address - prints address of input in hexa format
 ** @spec_arg: va_list arguments from _printf
 ** @d: pointer to the struct flags that determines
 * * if a flag is passed to _printf
 * * Return: number of char printed
 */
int print_address(va_list spec_arg, indi *d)
{
	char *str;
	unsigned long int p = va_arg(spec_arg, unsigned long int);

	register int count = 0;

	(void)d;

	if (!p)
		return (_puts("(nil)"));
	str = spec_convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
