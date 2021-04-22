#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*udest;
	unsigned char	*usrc;

	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	if (!(udest || usrc))
		return (0);
	i = 0;
	while (i < n)
	{
		udest[i] = usrc[i];
		i++;
	}
	return (dest);
}
