#include <stdlib.h>
#include "holberton.h"

/**
 * is_digit - Checks if a string is composed only of digits
 * @s: String to check
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - Returns the length of a string
 * @s: The string
 * Return: Length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_error - Prints error and exits with status 98
 */
void print_error(void)
{
	char *err = "Error\n";
	int i = 0;

	while (err[i])
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: First number string
 * @num2: Second number string
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int *result;
	int i, j, mul, sum, carry;

	result = malloc(sizeof(int) * (len1 + len2));
	if (!result)
		exit(98);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
		_putchar('0');

	for (; i < len1 + len2; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
	free(result);
}

/**
 * main - Entry point to multiply two numbers
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 if success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}
