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
	int i;
	char *s;
	int count = 0;
	va_list arg;

	va_start(arg, format);

	for (round = format; *round != '\0'; round++)
	{
		if (*round != '%')
		{
			putchar(*round);
			count++;
			continue;
		}
		round++;
		switch (*round)
		{
			case 'i':
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = -i;
					putchar('-');
					count++;
				}
				fputs(convert(i, 10), stdout);
				break;
			case 'd':
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = -i;
					putchar('-');
					count++;
				}
				fputs(convert(i, 10), stdout);
				break;
			case 'c':
				i = va_arg(arg, int);
				putchar(i);
				count++;
				break;
			case 's':
				s = va_arg(arg, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
				break;
			case '%':
				putchar('%');
				break;
			case 'b':
				i = va_arg(arg, int);
				if (i < )
				{
					i = -i;
					putchar('1');
					count++;
				}
				fputs(convert(i, 2), stdout);
				break;
			case 'o':
				i = va_arg(arg, unsigned int);
				puts(convert(i, 8));
				break;
			case 'x':
				i = va_arg(arg, unsigned int);
				puts(convert(i, 16));
				break;
			default:
				return (-1);
		}
	}
	va_end(arg);
	return (count);
}
