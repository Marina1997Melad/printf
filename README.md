printf project by Marina Demian and Oluwasayo Alaba
Description:
the printf() is pre-defined function from the header stdio.h. it's used to write formatted output to console . it sends formatted output to stdout.
A custom _printf() was developed by us.
_printf() function format string is a character string, beginning and ending in it's initial shift state, if any these arguments are placed using the percentage '%' operator.

compilation:

the code must be compiled this way :gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c

Examples:

len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");
ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;
_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);
_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);
