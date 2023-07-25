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
			count++;
			helper(format, count, args);
		} else
		{
		count += printf("%c", *format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
