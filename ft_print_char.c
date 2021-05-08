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
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.minus && flags.zero)
		flags.zero = 0;
	if (flags.precision == -1)
		flags.precision = len;
	if (flags.precision > len)
		flags.precision = len;
	if (flags.minus == 1)
		i += write(1, str, flags.precision);
	if (flags.zero)
		i += ft_putnchar('0', flags.width - flags.precision);
	else
		i += ft_putnchar(' ', flags.width - flags.precision);
	if (flags.minus == 0)
		i += write(1, str, flags.precision);
	return (i);
}
