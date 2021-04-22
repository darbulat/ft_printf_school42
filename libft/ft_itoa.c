#include "libft.h"

static int	ft_get_rank(unsigned int un)
{
	int	i;

	if (un < 10)
		return (1);
	i = 1000000000;
	while (un / i == 0)
		i /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	un;
	int			i;
	int			j;

	j = 0;
	un = (long int)n;
	str = malloc(12 * sizeof(*str));
	if (0 == str)
		return (0);
	if (un < 0)
	{
		un = -un;
		str[j++] = '-';
	}
	i = ft_get_rank(un);
	while (i)
	{
		str[j++] = (char)(un / i + '0');
		un %= i;
		i /= 10;
	}
	str[j] = 0;
	return (str);
}
