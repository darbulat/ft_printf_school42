#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	j;

	if (src == NULL)
		return (0);
	if (size == 0 || !dst)
		return (ft_strlen(src));
	j = 0;
	while (src[j] && j < (size - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = 0;
	return (ft_strlen(src));
}
