#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	int i;
	va_list args;
	va_start(args, format);

		while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				switch (*format)
				{case 'c':
					{
						int c = va_arg(args, int);
						_putchar(c);
						printed_chars++;
						break;
					}
					case 's':
					{
						char *str = va_arg(args, char *);
						for (i = 0; str[i] != '\0'; i++)
						{
							_putchar(str[i]);
							printed_chars++;
						}
						break;
					}
					case '%':
					{
						_putchar('%');
						printed_chars++;
						break;
					}
					default: 
					{
						break;
					}
				}
			} else
			{
				_putchar(*format);
				printed_chars++;
			}
			format++;
		}
	va_end(args);
	return (printed_chars);
}

