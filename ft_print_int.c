#include "ft_printf.h"

static int	print_str(char *str, int len, t_flags flags)
{
	int	i;

	i = ft_putnchar('0', flags.precision - len);
	write(1, str, len);
	return (i);
}

int	ft_print_unsigned(unsigned int unbr, t_flags flags)
{
	int		i;
	int		len;
	char	*str;

	if (unbr == 0 && flags.precision == 0)
		return (ft_putnchar(' ', flags.width));
	if (flags.minus && flags.zero)
		flags.zero = 0;
	str = ft_unsigned_itoa(unbr);
	len = ft_strlen(str);
	if (flags.zero && flags.precision == -1)
		flags.precision = flags.width;
	if (flags.precision < len)
		flags.precision = len;
	i = 0;
	if (flags.minus)
		i += print_str(str, len, flags);
	i += ft_putnchar(' ', flags.width - flags.precision);
	if (flags.minus == 0)
		i += print_str(str, len, flags);
	free(str);
	return (len + i);
}

int	ft_print_int(int nbr, t_flags flags)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (nbr >= 0)
		return (ft_print_unsigned(nbr, flags));
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	if (flags.precision < len && flags.zero == 0)
	{
		flags.precision = len;
		return (ft_print_string(str, flags));
	}
	if (flags.zero && flags.precision == -1)
		flags.precision = flags.width;
//	if (flags.precision < len)
//		flags.precision = len;
//	flags.precision++;
	if (flags.minus == 1)
	{
		ft_putchar_fd('-', 1);
		i += print_str(str + 1, len - 1, flags);
	}
	while (++i < flags.width - len + 1)
		ft_putchar_fd(' ', 1);
	if (flags.minus == 0)
	{
		ft_putchar_fd('-', 1);
		i += print_str(str + 1, len - 1, flags);
	}
	return (len + i + 1);
}