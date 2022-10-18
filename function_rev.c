#include "main.h"
/**
 * print_rev - prints a string in reverse
 * @spec_arg: argument from _printf
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list spec_arg, indi *d)
{
	int i = 0, j;
	char *s = va_arg(spec_arg, char *);

	(void)d;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @spec_arg: list of arguments from _printf
 * @d: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rot13(va_list spec_arg, indi *d)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(spec_arg, char *);

	(void)d;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_percent - prints a percent
 * @spec_arg: va_list arguments from _printf
 * @d: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percent(va_list spec_arg, indi *d)
{
	(void)spec_arg;
	(void)d;
	return (_putchar('%'));
}
