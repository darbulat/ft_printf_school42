#include "ft_printf.h"

int	ft_print_arg(va_list ap, t_flags flags)
{
	int		i;

	i = 0;
	if (flags.type == 'c')
		i += ft_print_char(va_arg(ap, int), flags);
	else if (flags.type == 's')
		i += ft_print_string(va_arg(ap, char *), flags);
	else if (flags.type == 'd' || flags.type == 'i')
		i += ft_print_int(va_arg(ap, int), flags);
	else if (flags.type == 'u')
		i += ft_print_unsigned(va_arg(ap, int), flags);
	else if (flags.type == 'X')
		i += ft_print_x(va_arg(ap, unsigned int), 0, flags);
	else if (flags.type == 'x')
		i += ft_print_x(va_arg(ap, unsigned int), 1, flags);
	else if (flags.type == 'p')
		i += ft_print_p(va_arg(ap, unsigned long long), flags);
	else if (flags.type == '%')
		i += ft_print_percent(flags);
	else
		i += write(1, &flags.type, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count_bytes;
	va_list	ap;
	t_flags	flags;

	i = 0;
	count_bytes = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i += ft_parse_flags(&format[i + 1], &flags, ap);
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
