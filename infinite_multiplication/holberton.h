#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stddef.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * is_digit - Checks if a string is composed only of digits
 * @s: String to check
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s);

/**
 * _strlen - Returns the length of a string
 * @s: The string
 * Return: Length
 */
int _strlen(char *s);

/**
 * print_error - Prints error and exits with status 98
 */
void print_error(void);

/**
 * multiply - Multiplies two positive numbers
 * @num1: First number string
 * @num2: Second number string
 */
void multiply(char *num1, char *num2);

#endif /* HOLBERTON_H */
