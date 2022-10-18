#include "main.h"

/**
 * spec_indi - turns on indicator if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @d: pointer to the struct flags in which we turn on the indicaton
 *
 * Return: 1 if a indicator has been turned on, 0 otherwise
 */
int spec_indi(char s, indi *d)
{
	int i = 0;

	switch (s)
	{
		case '+':
			d->plus = 1;
			i = 1;
			break;
		case ' ':
			d->space = 1;
			i = 1;
			break;
		case '#':
			d->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
