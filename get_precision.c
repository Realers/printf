#include "main.h"
/**
 * _is_valid - will check char identetifier
 * @c: input char
 * Return: true or false
 */
bool _is_valid(char c)
{
	const char *valid_chars = "diouxXeEfFgGaAcs";
	int x;

	for (x = 0; valid_chars[x] != '\0'; x++)
	{
		if (c == valid_chars[x])
		{
			return (true);
		}
	}
	return (false);
}
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
	bool found_prec = false;

	if (format[j] != '.')
		return (p);
	p = 0;
	found_prec = true;
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
	if (found_prec)
	{
		if (_is_valid(format[j]))
		{
			p = -1;
		}
	}
	return (p);
}
