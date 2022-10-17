#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
*struct spec_func - pointer array of specified functions
*@c: specifier character
*@p: pointer
*/
typedef struct spec_func
{
	char *c;
	int (*p)(va_list spec_arg);
} spec;

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int (*get_specifier(char s))(va_list);
int print_string(va_list arg);
int print_char(va_list arg);
int print_int(va_list arg);

/**
*spec_convert - converts number and base to string
*/
char *spec_convert(unsigned long int num, int base, int lowercase)

#endif
