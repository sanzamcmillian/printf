#include "main.h"

/**
 *convert - converts num to prefered base
 *
 *@num: the integer value to be converted
 *@base: integer to be used for conversion of num
 *Return: ptr
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
                *--ptr = representation[num % base];
                num /= base;
        } while (num != 0);

        return (ptr);
}
