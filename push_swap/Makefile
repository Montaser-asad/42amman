CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

CFILES = push_swap.c


OFILES = $(CFILES:.c=.o)


all : $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFILES) -o $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus