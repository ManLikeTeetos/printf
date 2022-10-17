#include "main.h"

/**
 * get_specifier - a struct array of specifier and their respective functions
 * depending on the conversion specifier passed to _printf
 * @s: given specifier
 * Return: a pointer to the function
 */

int (*get_specifier(char s))(va_list)
{
	spec spec_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{'b', print_binary},
	};
	int no_spec = 5;

	register int  i;

	for (i = 0; i < no_spec; i++)
		if (*spec_type[i].c == s)
			return (spec_type[i].p);
	return (NULL);
}

