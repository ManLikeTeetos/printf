#ifndef FILE_MAIN
#define FILE_MAIN

#include <stdarg.h>
#include <stdlib.h>

typedef struct print
{
    char *c;
    int (*p)(va_list spec_arg);
} spec;

int _putchar(char c);
int _printf(const char *format, ...);
int get_specifier(char s, va_list spec_arg);
int print_string(va_list arg);

#endif
