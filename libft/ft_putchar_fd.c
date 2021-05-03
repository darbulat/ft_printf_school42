#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnchar(char c, int i)
{
	if (i > 0)
		while (i--)
			write(1, &c, 1);
}