#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
		if (s[len - i++] == c)
			return ((char *)&s[len - (i - 1)]);
	return (NULL);
}
