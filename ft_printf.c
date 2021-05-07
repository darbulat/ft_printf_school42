#include "ft_printf.h"

int	ft_print_arg(va_list ap, t_flags flags)
{
	int		i;

	i = 0;
	if (flags.type == 'c')
		i += ft_print_char(va_arg(ap, int), flags);
	if (flags.type == 's')
		i += ft_print_string(va_arg(ap, char *), flags);
	if (flags.type == 'd' || flags.type == 'i')
		i += ft_print_int(va_arg(ap, int), flags);
	if (flags.type == 'u')
		i += ft_print_unsigned(va_arg(ap, int), flags);
//	if (flags.type == 'x')
//		i += ft_print_x(va_arg(ap, unsigned int), flags, 1);
//	if (flags.type == 'x')
//		i += ft_print_x(va_arg(ap, unsigned int), flags, 0);
	if (flags.type == '%')
		i += ft_putnchar('%', 1);
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
