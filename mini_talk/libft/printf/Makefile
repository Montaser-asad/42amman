CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
CFILES = ft_putstr.c ft_putnbr.c ft_puthex.c ft_printf.c ft_putptr.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re