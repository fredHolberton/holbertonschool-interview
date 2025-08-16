#include "regex.h"

/**
 * regex_match - checks if a pattern matches a given string
 * @str: the string to scan
 * @pattern: the regular expression pattern
 *
 * Return: 1 if pattern matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	/* If next char is '*', handle repetition */
	if (*(pattern + 1) == '*')
	{
		/* Case 1: skip "x*" in pattern (zero occurrence) */
		if (regex_match(str, pattern + 2))
			return (1);

		/* Case 2: first char matches, consume one char of str */
		if ((*str != '\0') &&
		    (*pattern == '.' || *pattern == *str))
			return (regex_match(str + 1, pattern));
		return (0);
	}

	/* Single char match (either exact or with '.') */
	if ((*str != '\0') &&
	    (*pattern == '.' || *pattern == *str))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
