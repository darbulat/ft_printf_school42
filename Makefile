CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR      = ar rcs

NAME = libftprintf.a
LIBFT = libft/libft.a
LIB_PATH = ./libft

SRCS = ft_printf.c

OBJECTS = $(SRCS:.c=.o)
HEADER = ft_printf.h

all:	makelibft $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(HEADER)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJECTS)

%.o:	%.c $(HEADER)
		@$(CC) $(CFLAGS) $< -o $@

makelibft:
		@$(MAKE) -C $(LIB_PATH)

clean:
	rm -f *.o
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

run: all
	@$(CC) main.c -L. -lftprintf -o runprintf && ./runprintf

.PHONY:	all clean fclean re