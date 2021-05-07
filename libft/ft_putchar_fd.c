#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putnchar(char c, int i)
{
	int	j;

	if (i <= 0)
		return (0);
	j = -1;
	while (++j < i)
		write(1, &c, 1);
	return (j);
}
