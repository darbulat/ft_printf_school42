CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR      = ar rcs

NAME = libftprintf.a
SRCS=./libft/ft*.c ./source/ft*.c

OBJECTS=ft*.o
LIB_PATH = ./libft
INCLUDES=./includes

all:$(NAME)

$(NAME):
	make re -C $(LIB_PATH)
	$(CC) -g3 $(CFLAGS) $(SRCS) -I$(INCLUDES)
	$(AR) $(NAME) $(OBJECTS) $(LIB_PATH)/*.o

clean:
	rm -f $(OBJECTS)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	$(CC) -static main.c -Lftprintf -o runprintf

.PHONY:	all clean fclean re