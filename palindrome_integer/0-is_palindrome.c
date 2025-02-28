#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome or not
 * @n: unsigned long
 * Return: 1 if the long is a palindrome, other wise return 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reversed = 0;

	while (n > 0) {
		unsigned long digit = n % 10;
		reversed = reversed * 10 + digit;
		n /= 10;
	}

	return original == reversed;
}

