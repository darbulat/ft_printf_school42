#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*us1;
	unsigned const char	*us2;
	size_t				i;

	us1 = (unsigned const char *)s1;
	us2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
