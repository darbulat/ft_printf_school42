#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int	ft_parse_flags(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	if (*format == 'c')
	{
		flags->type = 'c';
		i++;
	}
	else if (*format == '%')
	{
		flags->type = '%';
		i++;
	}
	return (i);
}

int	ft_print_arg(va_list ap, t_flags flags)
{
	char	c;

	c = va_arg(ap, int);
	if (flags.type == 'c')
		ft_putchar_fd(c, 1);
	if (flags.type == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count_bytes;
	va_list	ap;
	t_flags	flags;

	i = 0;
	flags = ft_init_flags();
	count_bytes = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i += ft_parse_flags(&format[i + 1], &flags);
			count_bytes += ft_print_arg(ap, flags);
		}
		else if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			count_bytes++;
		}
		i++;
	}
	va_end(ap);
	return (count_bytes);
}
