#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct indicators - struct containing indicators to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct indicators
{
	int plus;
	int space;
	int hash;
} indi;

/**
*struct spec_func - pointer array of specified functions
*@c: specifier character
*@p: pointer
*/
typedef struct spec_func
{
	char *c;
	int (*p)(va_list spec_arg, indi *d);
} spec;

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int (*get_specifier(char s))(va_list, indi *);
int print_string(va_list arg, indi *d);
int print_char(va_list arg, indi *d);
int print_int(va_list arg, indi *d);
int print_binary(va_list arg, indi *d);
int print_unsigned(va_list arg, indi *d);
int print_hex(va_list arg, indi *d);
int print_hex_big(va_list arg, indi *d);
int print_octal(va_list arg, indi *d);
int print_bigS(va_list arg, indi *d);
int print_address(va_list arg, indi *d);
int count_num(int i);
void print_number(int n);

/**
*spec_convert - converts number and base to string
* @num: number
* @base: base
* @lowercase: if hexa values should be in lowercase
* Return: result string
*/
char *spec_convert(unsigned long int num, int base, int lowercase);

/**
 * spec_indi - turns on indicator if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @d: pointer to the struct flags in which we turn on the indicaton
 *
 * Return: 1 if a indicator has been turned on, 0 otherwise
 */
int spec_indi(char s, indi *d);

#endif
