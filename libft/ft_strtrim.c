#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	l;
	size_t	r;

	if (!s1 || !set)
		return (NULL);
	l = 0;
	while (s1[l] && ft_strchr(set, s1[l]) != 0)
		l++;
	r = ft_strlen(s1);
	while (r > l && ft_strchr(set, s1[r - 1]) != 0)
		r--;
	str = (char *)malloc(sizeof(*s1) * (r - l + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (l < r)
		str[i++] = s1[l++];
	str[i] = 0;
	return (str);
}
