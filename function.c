#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * print_char - called from _printf
 * @arg: char
 * Return: int
 */
int print_char(va_list arg)
{
    char c;

    c = va_arg(arg, int);
    _putchar(c);
    return (1);
}
/**
 * print_string - called from _printf
 * @arg: string
 * Return: int
 */
int print_string(va_list arg)
{
    char *s;
    int i;

    s = va_arg(arg, char *);
    if (s == NULL)
        s = "(null)";
    for (i = 0; s[i] != '\0'; i++)
        _putchar(s[i]);
    return (i);
}
