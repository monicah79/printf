#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print - struct for conversion specifiers
 * @print: struct print
 * @p: print function specified
 */
typedef struct print
{
	char *print;
	int (*p)();
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);

int p_char(va_list arg);
int p_str(va_list arg);
int p_dec(va_list arg);
int p_int(va_list arg);

#endif
