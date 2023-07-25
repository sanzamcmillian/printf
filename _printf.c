#include <stdio.h>
#include <stdarg.h>

/**
 *
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
		count++;
		while( *round != '%')
		{
			putchar(*round);
			round++;
		}

		round++;

		switch(*round)
		{
			case 'c' : i = va_arg(arg, int);
				putchar(i);
				break;
			case 's' : s = va_arg(arg, char *);
				puts(s);
				break;
		}
	}
	va_end(arg);
	return (count);
}

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
