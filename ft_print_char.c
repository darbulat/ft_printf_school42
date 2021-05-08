#include "ft_printf.h"


int	ft_print_with_0(char *str, t_flags flags)
{
	int	i;

	i = 0;
	i += ft_putnchar('0', flags.precision - (int)ft_strlen(str));
	if (flags.precision > (int)ft_strlen(str))
		flags.precision = ft_strlen(str);
	i += write(1, str, flags.precision);
	return (i);
}

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
	if (flags.width == 0 && flags.precision == -1)
		flags.width = ft_strlen(str);
	if (flags.zero && flags.precision != -1 && flags.width)
		flags.precision = flags.width;
	else if (flags.precision == -1 || flags.precision > len)
		flags.precision = len;
	if (flags.minus == 1)
		i += ft_print_with_0(str, flags);
	i += ft_putnchar(' ', flags.width - flags.precision);
	if (flags.minus == 0)
		i += ft_print_with_0(str, flags);
	return (i);
}

int ft_print_percent(char *str, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.precision == 0)
		flags.precision = -1;
	i += ft_print_string(str, flags);
	return (i);
}
