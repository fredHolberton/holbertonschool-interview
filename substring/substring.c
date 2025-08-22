#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * word_index - find index of a word in array
 * @word: word to find
 * @words: array of words
 * @nb_words: number of words
 *
 * Return: index if found, -1 otherwise
 */
static int word_index(const char *word, const char **words, int nb_words)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (strcmp(word, words[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * build_count - build frequency table of words
 * @words: list of words
 * @nb_words: number of words
 *
 * Return: allocated int array of counts
 */
static int *build_count(const char **words, int nb_words)
{
	int *count, i, j, found;

	count = calloc(nb_words, sizeof(int));
	if (!count)
		return (NULL);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < i; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
			{
				count[j]++;
				found = 1;
				break;
			}
		}
		if (!found)
			count[i] = 1;
	}
	return (count);
}

/**
 * is_valid_substring - check if substring matches concatenation
 * @s: substring start
 * @words: list of words
 * @nb_words: number of words
 * @word_len: length of each word
 * @count: frequency table of words
 *
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid_substring(const char *s, const char **words,
		int nb_words, int word_len, int *count)
{
	int *used, i, idx;
	char *tmp;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	tmp = malloc(word_len + 1);
	if (!tmp)
	{
		free(used);
		return (0);
	}

	for (i = 0; i < nb_words; i++)
	{
		strncpy(tmp, s + i * word_len, word_len);
		tmp[word_len] = '\0';

		idx = word_index(tmp, words, nb_words);
		if (idx == -1)
		{
			free(tmp);
			free(used);
			return (0);
		}
		used[idx]++;
		if (used[idx] > count[idx])
		{
			free(tmp);
			free(used);
			return (0);
		}
	}

	free(tmp);
	free(used);
	return (1);
}

/**
 * find_substring - find all starting indices of valid substrings
 * @s: string to scan
 * @words: list of words
 * @nb_words: number of words
 * @n: pointer to result count
 *
 * Return: malloc'd array of indices, or NULL if none
 */
int *find_substring(char const *s, char const **words,
		int nb_words, int *n)
{
	int s_len, word_len, sub_len, i, count_found = 0;
	int *indices, *count;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	word_len = strlen(words[0]);
	if (word_len == 0)
		return (NULL);

	s_len = strlen(s);
	sub_len = nb_words * word_len;

	if (s_len < sub_len)
		return (NULL);

	count = build_count(words, nb_words);
	if (!count)
		return (NULL);

	indices = malloc(sizeof(int) * (s_len - sub_len + 1));
	if (!indices)
	{
		free(count);
		return (NULL);
	}

	for (i = 0; i <= s_len - sub_len; i++)
	{
		if (is_valid_substring(s + i, words, nb_words, word_len, count))
			indices[count_found++] = i;
	}

	free(count);

	if (count_found == 0)
	{
		free(indices);
		return (NULL);
	}
	*n = count_found;
	return (indices);
}
