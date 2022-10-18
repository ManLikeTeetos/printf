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
	int  printlen = 0;
	const char *v;


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
			}
			else
			{
				while (spec_indi(*v, &indicators))
					v++;
				specfunc = get_specifier(*v);
				printlen += (specfunc) ? specfunc(spec_arg, &indicators) : _printf("%%%c", *v);
			}
		}
		else
		{
			_putchar(*v);
			printlen++;
		}
	}
	_putchar(-1);
	va_end(spec_arg);
	return (printlen);
}
