#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - checks if a pattern matches a given string
 * @str: the string to scan
 * @pattern: the regular expression pattern
 *
 * Return: 1 if pattern matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
