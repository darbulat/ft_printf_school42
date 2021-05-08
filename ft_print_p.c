#include "ft_printf.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	print_with_0(char *str, t_flags flags)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	i += ft_putnchar('0', flags.precision - (int)ft_strlen(str));
	i += write(1, str, ft_strlen(str));
	return (i);
}

static int	print_p(unsigned long long unbr, t_flags flags)
{
	char	*str;
	int		i;

	i = 0;
	if (flags.precision == 0 && unbr == 0)
		return (ft_putnchar(' ', flags.width));
	str = ft_itoa_base(unbr, 16, 1);
	if (flags.minus)
		i += print_with_0(str, flags);
	if (flags.precision != -1)
		flags.precision = ft_max(flags.precision, ft_strlen(str));
	if ((flags.zero && flags.precision < (int)ft_strlen(str))
		|| (flags.zero && flags.precision == -1))
		flags.precision = flags.width;
	else if (flags.precision == -1 || flags.precision < (int)ft_strlen(str))
		flags.precision = ft_strlen(str);
	i += ft_putnchar(' ', flags.width - flags.precision - 2);
	if (!flags.minus)
		i += print_with_0(str, flags);
	free(str);
	return (i);
}

static int	ft_print_null_p(t_flags flags)
{
	int	i;

	i = 0;
	if (flags.precision == -1)
		flags.precision = 1;
	if (flags.minus)
	{
		i += write(1, "0x", 2);
		i += ft_putnchar('0', flags.precision);
	}
	i += ft_putnchar(' ', flags.width - flags.precision - 2);
	if (flags.minus == 0)
	{
		i += write(1, "0x", 2);
		i += ft_putnchar('0', flags.precision);
	}
	return (i);
}

int	ft_print_p(unsigned long long unbr, t_flags flags)
{
	int		i;

	i = 0;
	if (unbr == 0)
		return (ft_print_null_p(flags));
	i += print_p(unbr, flags);
	return (i);
}
