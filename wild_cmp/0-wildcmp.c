#include "holberton.h"

/**
 * wildcmp - Compares two strings considering '*' as a wildcard
 * @s1: First string (input)
 * @s2: Second string (pattern, may contain '*')
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		/* Try to match 0 characters or 1+ characters */
		return (
			wildcmp(s1, s2 + 1) ||
			(*s1 != '\0' && wildcmp(s1 + 1, s2))
		);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
