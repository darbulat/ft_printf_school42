#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*tmp;

	tmp = (size_t *)malloc(nmemb * size);
	if (tmp)
		ft_memset(tmp, 0, nmemb * size);
	return (tmp);
}
