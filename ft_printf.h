#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				precision;
}					t_flags;

int	ft_printf(const char *format, ...);
int	ft_parse_flags(const char *format, t_flags *flags, va_list ap);
int	ft_print_char(char c, t_flags flags);
int	ft_print_string(char *str, t_flags flags);
int	ft_print_int(int nbr, t_flags flags);
int	ft_print_unsigned(unsigned int unbr, t_flags flags);
int	ft_print_x(unsigned int unbr, int is_lower, t_flags flags);

#endif
