#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

int handle_char(va_list args, int count)
{
    count += printf("%c", va_arg(args, int));
    return count;
}

int handle_string(va_list args, int count)
{
    count += printf("%s", va_arg(args, char *));
    return count;
}

int handle_decimal(va_list args, int count)
{
    char buffer[12];
    int num = va_arg(args, int);
    int len = sprintf(buffer, "%d", num);
    count += printf("%.*s", len, buffer);
    return count;
}

int handle_unsigned(va_list args, int count)
{
    count += printf("[%u]", va_arg(args, unsigned int));
    return count;
}

int handle_octal(va_list args, int count)
{
    count += printf("[%o]", va_arg(args, unsigned int));
    return count;
}

int handle_hex(va_list args, int count, char format)
{
    unsigned int num = va_arg(args, unsigned int);
    if (format == 'x') {
        count += printf("[%08x, %08X]", num, num);
    }
    return count;
}

int handle_pointer(va_list args, int count)
{
    count += printf("[%p]", va_arg(args, void *));
    return count;
}

int handle_percent(int count)
{
    count += printf("%%");
    return count;
}

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
        }
        else
        {
            count += printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    return count;
}
