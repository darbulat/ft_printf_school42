#include "ft_printf.h"

int	ft_get_flag(const char *format, t_flags *flags)
{
	int	i;

	flags->minus = 0;
	flags->zero = 0;
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

int	ft_get_width(const char *format, int *width, va_list ap)
{
	int	i;

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

int	ft_get_precision(const char *format, int *precision, va_list ap)
{
	int	i;

	*precision = -1;
	if (format[0] != '.')
		return (0);
	*precision = 0;
	i = ft_get_width(&format[1], precision, ap) + 1;
	if (*precision < 0)
		*precision = -1;
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
	flags->type = 0;
	if (format[i])
		flags->type = format[i++];
	return (i);
}
