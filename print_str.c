#include "main.h"
#include <string.h>

int *print_str(char *c, int *i)
{
    int j = 0;
    while (c[j] != '\0')
        {
           _putchar(c[j]);
                (*i)++;
        }
    return (i);
}