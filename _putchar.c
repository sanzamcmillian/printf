#include <stdio.h>

/**
* _putchar - prints a char
* @c: char to be printed
* Return: c otherwise 0 if unsuccessful
*/

int _putchar(char c)
{
	return write(1, &c, 1);
}
