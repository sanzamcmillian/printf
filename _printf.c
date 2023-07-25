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

	for (round = format; *round != '\0'; round++)
	{
		count++;
		if (*round != '%')
		{
			putchar(*round);
			continue;
		}
		round++;
		if (*round == '%')
		{
			putchar('%');
			continue;
		}
		switch (*round)
		{
			case 'c':
				i = va_arg(arg, int);
				putchar((char)i);
				break;
			case 's':
				s = va_arg(arg, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
				}
				break;
			case '%':
				putchar('%');
				break;
			case 'd':
				i = va_arg(arg, int);
				if (i < 0)
				{
					putchar('-');
					count++;
					i = -i;
				}
				puts(convert(i, 10));
				break;
			case 'i':
				i = va_arg(arg, int);
				puts(convert(i, 10));
				break;
		}
	}
	va_end(arg);
	return (count);
}
