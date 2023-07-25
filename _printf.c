#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Prints a string
 * @format: List a of arguments
 * Return: Number of chars printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int num;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += printf("%c", va_arg(args, int));
			else if (*format == 's')
				count += printf("%s", va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);
				count += printf("[%d, %i]", num, num);
			}
			else if (*format == 'u')
				count += printf("[%u]", va_arg(args, unsigned int));
			else if (*format == 'o')
				count += printf("[%o]", va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += printf("[%x, %X]", num, num);
			}
			else if (*format == 'p')
				count += printf("[%p]", va_arg(args, void *));
			else if (*format == '%')
				count += printf("%%");
			else
				count += printf("%%%c", *format);
		}
		else
			count += printf("%c", *format);
		format++;
	}
	va_end(args);
	return (count);
}
