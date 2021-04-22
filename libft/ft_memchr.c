#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*us;
	size_t				i;

	us = (unsigned const char *)s;
	i = 0;
	while (i < n)
	{
		if (us[i] == (unsigned char)c)
			return ((void *)&us[i]);
		i++;
	}
	return (0);
}
