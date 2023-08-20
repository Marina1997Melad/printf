#include "main.h"
/**
 * handle_print - prints argument based on it's type
 * @fmt: formatted string in which to print arguments
 * @list: list of arguments
 * @i: list of arguments to be printed
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int j, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'s', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (j = 0; fmt_types[j].fmt != '\0'; j++)
		if (fmt[*i] == fmt_types[j].fmt)
			return (fmt_types[j].fn(list, buffer, flags, width, precision, size));
	if (fmt_types[j].fmt == '\0')
	{
	if (fmt[*i] == '\0')
		return (-1);
	unknown_len += write(1, "%%", 1);
	if (fmt[*i - 1] == ' ')
		unknown_len += write(1, " ", 1);
	else if (width)
	{
		--(*i);
		while (fmt[*i] != ' ' && fmt[*i] != '%')
			--(*i);
		if (fmt[*i] == ' ')
			--(*i);
		return (1);
	}
	unknown_len += write(1, &fmt[*i], 1);
	return (unknown_len);
	}
	return (printed_chars);
}
