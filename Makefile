NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs

SRCS = ft_printf.c \
		ft_putnbr.c \
		ft_print_hex.c \
		ft_print_ptr.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putunsigned.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re