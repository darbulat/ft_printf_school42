#include "ft_printf.h"


static int	print_with_0(t_flags flags)
{
	int	i;

	i = 0;
	i += ft_putnchar('0', flags.precision - 1);
	i += write(1, "%", 1);
	return (i);
}

static int	print_string(t_flags flags)
{
	int	i;

	i = 0;
	if (flags.width == 0 && flags.precision == -1)
		flags.width = 1;
	if (flags.zero && flags.width)
		flags.precision = flags.width;
	else if (flags.precision == -1 || flags.precision > 1)
		flags.precision = 1;
	if (flags.minus == 1)
		i += print_with_0(flags);
	i += ft_putnchar(' ', flags.width - flags.precision);
	if (flags.minus == 0)
		i += print_with_0(flags);
	return (i);
}

int ft_print_percent(t_flags flags)
{
	int	i;

	i = 0;
	if (flags.precision == 0)
		flags.precision = -1;
	if (flags.zero && flags.minus)
		flags.zero = 0;
	i += print_string(flags);
	return (i);
}
