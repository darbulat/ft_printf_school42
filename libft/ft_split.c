#include "libft.h"

int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;
	int	new_word;

	new_word = 1;
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			new_word = 1;
		else if (new_word)
		{
			count++;
			new_word = 0;
		}
	}
	return (count);
}

char	*ft_get_first_word(char **pstr, char c)
{
	char	*word;
	int		i;
	int		j;

	while (**pstr == c)
		(*pstr)++;
	i = 0;
	while ((*((*pstr) + i)) && (((*((*pstr) + i) != c))))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if ((void *)0 == word)
		return ((void *)0);
	j = 0;
	while (j < i)
	{
		word[j] = *((*pstr) + j);
		j++;
	}
	(*pstr) += j;
	word[j] = 0;
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		count_words;
	char	*s;

	if (!str)
		return (NULL);
	s = ft_strdup(str);
	count_words = ft_count_words(s, c);
	strs = malloc(sizeof(char *) * (count_words + 1));
	if ((void *)0 == strs)
		return ((void *)0);
	i = 0;
	while (i < count_words)
	{
		strs[i] = ft_get_first_word(&s, c);
		i++;
	}
	strs[i] = (void *)0;
	return (strs);
}
