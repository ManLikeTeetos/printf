#include <stdarg.h>
#include <stddef.h>
#include "main.h"
/**
 * _printf - called from main
 * @format: string
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list spec_arg;
	int (*specfunc)(va_list, indi *);
	int i, printlen = 0;
	const char *v;
	short flag = 0;

	indi indicators = {0, 0, 0};

	va_start(spec_arg, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (v = format; *v; v++)
	{
		if (*v == '%')
		{
			v++;
			if (*v == '%')
			{
				_putchar('%');
				printlen++;
				flag = 1;
			}
			else
			{
				while (spec_indi(*v, &indicators))
					v++;
				specfunc = get_specifier(*v);
				printlen += (specfunc) ? specfunc(spec_arg, &indicators) : _printf("%%%c", *v);
				flag = 1;
			}
			if (flag == 1)
				i++;
			else
			{
				_putchar('%');
				printlen++;
			}
		}
		else
		{
			_putchar(*v);
			printlen++;
		}
	}
	va_end(spec_arg);
	return (printlen);
}
