#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags		flags;

	flags.precision = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int	ft_get_flag(const char *format, t_flags *flags)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '-')
			flags->minus = 1;
		else
			return (i);
		i++;
	}
	return (i);
}

int ft_get_width(const char *format, int *width, va_list ap)
{
	int i;

	i = 0;
	*width = 0;
	if (format[i] == '*')
	{
		*width = va_arg(ap, int);
		return (++i);
	}
	while (format[i] >= '0' && format[i] <= '9')
	{
		*width = *width * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

int ft_get_precision(const char *format, int *precision, va_list ap)
{
	int i;

	*precision = -1;
	if (format[0] != '.')
		return (0);
	*precision = 0;
	i = ft_get_width(&format[1], precision, ap) + 1;
	if (*precision < 0)
		*precision = -*precision;
	return (i);
}

int	ft_parse_flags(const char *format, t_flags *flags, va_list ap)
{
	int	i;

	i = ft_get_flag(format, flags);
	i += ft_get_width(&format[i], &flags->width, ap);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	i += ft_get_precision(&format[i], &flags->precision, ap);
	if (format[i])
		flags->type = format[i++];
	return (i);
}

int ft_print_char(va_list ap, t_flags flags)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(ap, int);
	if (flags.minus == 1)
		ft_putchar_fd(c, 1);
	while (++i < flags.width)
		ft_putchar_fd(' ', 1);
	if (flags.minus == 0)
		ft_putchar_fd(c, 1);
	return (i);
}

int	ft_print_string(va_list ap, t_flags flags)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision == -1)
		flags.precision = len;
	if (flags.precision > len)
		flags.precision = len;
	if (flags.minus == 1)
		write(1, str, flags.precision);
	while (++i < flags.width - flags.precision + 1)
		ft_putchar_fd(' ', 1);
	if (flags.minus == 0)
		write(1, str, flags.precision);
	return (len);
}

int	ft_print_int(va_list ap, t_flags flags)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = ft_itoa(va_arg(ap, int));
	len = ft_strlen(str);
	if (flags.zero && flags.precision == -1)
		flags.precision = flags.width;
	if (flags.precision < len)
		flags.precision = len;
	if (*str == '-')
		flags.precision--;
	if (flags.minus == 1)
	{
		if (*str == '-')
			ft_putchar_fd(*str++, 1);
		ft_putnchar('0', flags.precision - len);
		write(1, str, ft_strlen(str));
	}
	while (++i < flags.width - len + 1)
		ft_putchar_fd(' ', 1);
	if (flags.minus == 0)
	{
		if (*str == '-')
			ft_putchar_fd(*str++, 1);
		ft_putnchar('0', flags.precision - len);
		write(1, str, ft_strlen(str));
	}
	return (len);
}

int	ft_print_unsigned(va_list ap, t_flags flags)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = ft_unsigned_itoa((unsigned int)va_arg(ap, int));
	len = ft_strlen(str);
	if (flags.zero && flags.precision == -1)
		flags.precision = flags.width;
	if (flags.precision < len)
		flags.precision = len;
	if (flags.minus == 1)
	{
		ft_putnchar('0', flags.precision - len);
		write(1, str, len);
	}
	while (++i < flags.width - flags.precision + 1)
		ft_putchar_fd(' ', 1);
	if (flags.minus == 0)
	{
		ft_putnchar('0', flags.precision - len);
		write(1, str, len);
	}
	return (len);
}

int	ft_print_arg(va_list ap, t_flags flags)
{
	char	c;
	int		i;

	i = 0;
	if (flags.type == 'c')
		i += ft_print_char(ap, flags);
	if (flags.type == 's')
		i += ft_print_string(ap, flags);
	if (flags.type == 'd' || flags.type == 'i')
		i += ft_print_int(ap, flags);
	if (flags.type == 'u')
		i += ft_print_unsigned(ap, flags);
	if (flags.type == '%')
		ft_putchar_fd('%', 1);
	return (i);
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
