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

		if (*round == '%')
		{
			putchar('%');
			count++;
			continue;
		}

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
			case 'd' : i = va_arg(arg, int);
				printf("%d", i);
				break;
			case 'i' : i = va_arg(arg, int);
				printf("%i", i);
				break;
		}
	}
	va_end(arg);
	return (count);
}

/**
 *convert - converts num to prefered base
 *
 *@num: the integer value to be converted
 *@base: integer to be used for conversion of num
 *Return: a character
 */

char *convert(unsigned int num, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = representation[num%base];
		num /= base;
	}while(num != 0);

	return (ptr);
}
