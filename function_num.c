#include "main.h"
/**
 *  * print_binary - prints a number in base 2
 *   * @spec_arg: va_list arguments from _printf
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert()
 * which in turns converts the input
 * * number into the correct base and returns it as a string
 * * Return: the number of char printed
 */
int print_binary(va_list spec_arg, indi *d)
{
	unsigned int num = va_arg(spec_arg, unsigned int);
	char *str = spec_convert(num, 2, 0);

	(void)d;
	return (_puts(str));
}
/**
 * print_hex - prints a number in hexadecimal base,
 * in lowercase
 * @spec_arg: va_list arguments from _printf
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turns converts the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */
int print_hex(va_list spec_arg, indi *d)
{
	unsigned int num = va_arg(spec_arg, unsigned int);
	char *str = spec_convert(num, 16, 1);
	int count = 0;

	if (d->hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}
/**
 * print_unsigned - prints an unsigned integer
 * @spec_arg: va_list of arguments from _printf
 * @d: pointer to the struct indicator determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list spec_arg, indi *d)
{
	unsigned int u = va_arg(spec_arg, unsigned int);
	char *str = spec_convert(u, 10, 0);

	(void)d;
	return (_puts(str));
}
/**
 ** print_hex_big - prints a number in hexadecimal base,
 ** in uppercase
 ** @spec_arg: va_list arguments from _printf
 ** @d: pointer to the struct that determines
 ** if a flag is passed to _printf
 * Description: the function calls convert() which in turns converts the input
 ** number into the correct base and returns it as a string
 ** Return: the number of char printed
 */
int print_hex_big(va_list spec_arg, indi *d)
{
	unsigned int num = va_arg(spec_arg, unsigned int);
	char *str = spec_convert(num, 16, 0);
	int count = 0;

	if (d->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}
/**
 *  * print_octal - prints a number in base 8
 ** @spec_arg: va_list arguments from _printf
 ** @d: pointer to the struct that determines
 ** if a flag is passed to _printf
 ** Description: the function calls convert() which in turns converts the input
 ** number into the correct base and returns it as a string
 ** Return: the number of char printed
 */
int print_octal(va_list spec_arg, indi *d)
{
	unsigned int num = va_arg(spec_arg, unsigned int);
	char *str = spec_convert(num, 8, 0);
	int count = 0;

	if (d->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}
