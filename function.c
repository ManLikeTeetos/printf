#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"

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
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_char - called from _printf
 * @spec_arg: char
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: int
 */
int print_char(va_list spec_arg, indi *d)
{
	char c;
	(void)d;

	c = va_arg(spec_arg, int);
	_putchar(c);
	return (1);
}
/**
 * print_string - called from _printf
 * @spec_arg: string
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: int
 */
int print_string(va_list spec_arg, indi *d)
{
	char *s;
	int i;

	s = va_arg(spec_arg, char *);

	(void)d;

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}
