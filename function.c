#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * handle_char - print a single character
 * @args: va_list of arguments
 * @count: number of characters printed
 * Return: number of characters printed
 */
int handle_char(va_list args, int count)
{
	count += printf("%c", va_arg(args, int));
	return (count);
}
/**
 * handle_string - print a string
 * @args: va_list of arguments
 * @count: number of characters printed
 * Return: number of characters printed
 */
int handle_string(va_list args, int count)
{
	count += printf("%s", va_arg(args, char *));
	return (count);
}
/**
 * handle_decimal - print a decimal integer
 * @args: va_list of arguments
 * @count: number of characters printed
 * Return: number of characters printed
 */
int handle_decimal(va_list args, int count)
{
	char buffer[12];
	int num = va_arg(args, int);
	int len = sprintf(buffer, "%d", num);

	count += printf("%.*s", len, buffer);
	return (count);
}
/**
 * handle_unsigned - print an unsigned integer
 * @args: va_list of arguments
 * @count: number of characters printed
 *
 * Return: updated count of characters printed
 */
int handle_unsigned(va_list args, unsigned int count)
{
	count += printf("%u", va_arg(args, unsigned int));
	return (count);
}
/**
 * helper - Entry point
 *@format: print char
 *@count: print int
 *@args: prent args
 * Return: Always 0
 */
void helper(const char *format, unsigned int count, va_list args)
{
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

}
