#include "ft_printf.h"

int	ft_print_char(char c, t_flags flags)
{
	int		i;

	i = 0;
	if (flags.minus == 1)
		ft_putchar_fd(c, 1);
	while (++i < flags.width)
		ft_putchar_fd(' ', 1);
	if (flags.minus == 0)
		ft_putchar_fd(c, 1);
	return (i);
}

int	ft_print_string(char *str, t_flags flags)
{
	int		i;
	int		len;

	i = 0;
	if (!str && flags.precision < 6 && flags.precision > -1)
		str = "";
	else if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision == -1)
		flags.precision = len;
	if (flags.precision > len)
		flags.precision = len;
	if (flags.minus == 1)
		write(1, str, flags.precision);
	while (i < flags.width - flags.precision)
		i += ft_putnchar(' ', 1);
	if (flags.minus == 0)
		write(1, str, flags.precision);
	return (flags.precision + i);
}
