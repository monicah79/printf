#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * handle_octal - print an octal integer
 * @args: va_list of arguments
 * @count: number of characters printed
 *
 * Return: number of characters printed
 */
int handle_octal(va_list args, int count)
{
	count += printf("%o", va_arg(args, unsigned int));
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
		count += printf("%08x", num);
	}
	else if (format == 'X')
	{
		count += printf("%08X", num);
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
	count += printf("%p", va_arg(args, void *));
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
