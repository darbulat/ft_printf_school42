#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = ft_strlen(s) - 1;
	j = 0;
	while (j < i)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i--;
		j++;
	}
	return (s);
}
