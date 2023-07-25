#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints all characters
 * @format: formats the string used
 * Return: length of the string
 */

int _printf(const char *format, ...)
{
	const char *round;
	unsigned int i;
	char *s;
	int count = 0;

	va_list arg;
	va_start(arg, format);

	for(round = format; *round != '\0'; round++)
	{
		if( *round != '%')
		{
			putchar(*round);
			count++;
			continue;
		}

		round++;

		switch(*round)
		{
			case 'c' : i = va_arg(arg, int);
				putchar((char)i);
				count++;
				break;
			case 's' : s = va_arg(arg, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
				break;
			case '%' : putchar('%');
				break;
		}
	}
	va_end(arg);
	return (count);
}
