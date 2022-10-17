#include "main.h"
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
 * @arg: string
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
