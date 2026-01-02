CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = libft.a

NAME = push_swap

CFILES = push_swap.c ops.c


OFILES = $(CFILES:.c=.o)


all : $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFILES) -o $(NAME) $(LIB)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus