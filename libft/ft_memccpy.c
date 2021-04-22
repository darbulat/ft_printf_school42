#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*udest;
	unsigned char	*usrc;

	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	while (n--)
	{
		*udest = *usrc;
		udest++;
		if (*usrc == (unsigned char)c)
		{
			return (udest);
		}	
		usrc++;
	}
	return (0);
}
