#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int j = *i + 1;
	int p = -1;

	if (format[j] != '.')
		return (p);
	p = 0;
	for (j += 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			p *= 10;
			p += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			p = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = j - 1;
	return (p);
}
