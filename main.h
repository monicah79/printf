#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

int handle_char(va_list args, int count);
int handle_string(va_list args, int count);
int handle_decimal(va_list args, int count);
int handle_unsigned(va_list args, int count);
int handle_octal(va_list args, int count);
int handle_hex_lower(va_list args, int count);
int handle_hex_upper(va_list args, int count);
int handle_pointer(va_list args, int count);
int handle_percent(int count);

#endif /* MAIN_H */
