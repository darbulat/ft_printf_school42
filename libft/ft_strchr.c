#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
		if (!s[i++])
			return (0);
	return ((char *)&s[i]);
}
