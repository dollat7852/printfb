#include "main.h"
#include <string.h>
#include <stddef.h>

int *print_str(char *c, int *i)
{
    if (c == NULL)
        return(0);
    int j = 0;
    while (c[j] != '\0')
        {
           _putchar(c[j]);
                (*i)++;
                j++;
        }
    return (i);
}