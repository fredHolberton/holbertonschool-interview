#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * find_substring - finds substring indices
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to store number of results
 *
 * Return: malloc'ed array of indices, NULL if none
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
