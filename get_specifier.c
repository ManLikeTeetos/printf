#include "main.h"

/**
 * get_specifier - a struct array of specifier and their respective functions
 * depending on the conversion specifier passed to _printf
 * @s: given specifier
 * Return: a pointer to the function
 */

int (*get_specifier(char s))(va_list){



    spec spec_type[] = {
        {"c", print_char},
        {"s", print_string},

        };
        int no_spec = 2;

        register int  i;
        for (i = 0; i < no_spec; i++)
            if (*spec_type[i].c == s)
                return (spec_type[i].p);
        return (NULL);
}

