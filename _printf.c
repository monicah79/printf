#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - Entry point
 *@format: print char
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count = handle_char(args, count);
					break;
				case 's':
					count = handle_string(args, count);
					break;
				case 'd':
				case 'i':
					count = handle_decimal(args, count);
					break;
				case 'u':
					count = handle_unsigned(args, count);
					break;
				case 'o':
					count = handle_octal(args, count);
					break;
				case 'x':
				case 'X':
					count = handle_hex(args, count, *format);
					break;
				case 'p':
					count = handle_pointer(args, count);
					break;
				case '%':
					count = handle_percent(count);
					break;
				default:
					count += printf("%%%c", *format);
					break;
			}
		} else 
		{
		count += printf("%c", *format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
