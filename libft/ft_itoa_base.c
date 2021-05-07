#include "libft.h"

char	*ft_itoa_base(unsigned int n, int b)
{

	char			*rtn;
	unsigned int	n;
	int				count;

	rtn = 0;
	count = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_save, base, rtn, count);
	return (rtn);
}
