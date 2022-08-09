#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * _printf - imitate printf function
 * @format: char pointer
 * Return:int
 */
int _printf(const char * const format, ...)
{
	int i = 0;
	int disp_count = 0;
	int *ip = &disp_count;
	
	va_list args;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			disp_count++;
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				i++;
				print_char(va_arg(args, int), ip);
				
			}
			else if (format[i + 1] == 's')
			{
				i++;
				disp_count += _printf(va_arg(args, char *));
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				disp_count++;
			}
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				i++;
				print_num(va_arg(args, int), ip);
			}
		}
		i++;
	}
	va_end(args);
	return (0);
}
