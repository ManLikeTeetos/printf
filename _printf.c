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
int i, printlen;
va_list spec_arg;
va_start(spec_arg, format);
short flag = 0;
_putchar(i);




    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
    {
        return (-1);
    }
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '%')
            {
                _putchar('%');
                printlen++;
                flag = 1;
            }
            else
            {

                printlen += get_specifier(format[i + 1], spec_arg);
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
            _putchar(format[i]);
            printlen++;
        }
    }
    va_end(spec_arg);
    return(printlen);
}
