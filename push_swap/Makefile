CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

NAME = push_swap

CFILES = push_swap.c short_sort.c utils.c sort.c parsing.c utils2.c\
		 operations/opsp.c operations/opsr.c operations/opsrr.c operations/opss.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft bonus

$(NAME): $(LIBFT) $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -Ilibft -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OFILES)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re