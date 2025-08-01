#include "holberton.h"

/**
 * wildcmp - Compares two strings, supporting '*' as a wildcard
 * @s1: First string (target)
 * @s2: Second string (pattern, may contain '*')
 *
 * Return: 1 if strings match (with wildcard support), 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		/* Skip consecutive * to handle cases like ** or *** */
		while (*s2 == '*')
			s2++;

		/* If * is the last char, it matches all remaining chars in s1 */
		if (*s2 == '\0')
			return (1);

		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2))
				return (1);
			s1++;
		}
		/* Try matching empty string */
		return (wildcmp(s1, s2));
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
