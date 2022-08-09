#include "main.h"
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
				print_char(va_arg(args, int), &disp_count);
				
			}
			else if (format[i + 1] == 's')
			{
				i++;
				disp_count += _printf(va_arg(args, char *));
				/* print_str(va_arg(args, char *), &disp_count); */
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				disp_count++;
			}
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				i++;
				print_num(va_arg(args, int), &disp_count);
			}
		}
		i++;
	}
	va_end(args);
	return (disp_count);
}
