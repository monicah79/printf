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
 * Return: number of characters printed
 */
int handle_unsigned(va_list args, int count)
{
	count += printf("[%u]", va_arg(args, unsigned int));
	return (count);
}
/**
 * handle_octal - print an octal integer
 * @args: va_list of arguments
 * @count: number of characters printed
 *
 * Return: number of characters printed
 */
int handle_octal(va_list args, int count)
{
	count += printf("[%o]", va_arg(args, unsigned int));
	return (count);
}
/**
 * handle_hex - print a hexadecimal integer
 * @args: va_list of arguments
 * @count: number of characters printed
 * @format: format specifier ('x' or 'X')
 *
 * Return: number of characters printed
 */
int handle_hex(va_list args, int count, char format)
{
	unsigned int num = va_arg(args, unsigned int);

	if (format == 'x')
	{
		count += printf("[%08x, %08X]", num, num);
	}
	return (count);
}
/**
 * handle_pointer - print a pointer address
 * @args: va_list of arguments
 * @count: number of characters printed
 *
 * Return: number of characters printed
 */
int handle_pointer(va_list args, int count)
{
	count += printf("[%p]", va_arg(args, void *));
	return (count);
}
/**
 * handle_percent - print a percent sign
 * @count: number of characters printed
 *
 * Return: number of characters printed
 */
int handle_percent(int count)
{
	count += printf("%%");
	return (count);
}
