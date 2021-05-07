#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strtolower(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		str[i] = (char)ft_tolower(str[i]);
	return (str);
}
