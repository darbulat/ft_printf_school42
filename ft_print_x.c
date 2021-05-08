#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_print_x(unsigned int unbr, int is_lower, t_flags flags)
{
	char	*str;
	int		i;

	i = 0;
	if (flags.precision == 0 && unbr == 0)
		return (ft_putnchar(' ', flags.width));
	str = ft_itoa_base(unbr, 16, is_lower);
	if (flags.minus)
		i += ft_print_with_0(str, flags);
	if (flags.precision != -1)
		flags.precision = ft_max(flags.precision, ft_strlen(str));
	if ((flags.zero && flags.precision < (int)ft_strlen(str))
		|| (flags.zero && flags.precision == -1))
		flags.precision = flags.width;
	else if (flags.precision == -1 || flags.precision < (int)ft_strlen(str))
		flags.precision = ft_strlen(str);
	i += ft_putnchar(' ', flags.width - flags.precision);
	if (!flags.minus)
		i += ft_print_with_0(str, flags);
	free(str);
	return (i);
}
