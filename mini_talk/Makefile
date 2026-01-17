CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(LIBFT):
	@make -C libft bonus

$(SERVER): $(LIBFT) server.o
	@$(CC) $(CFLAGS) server.o $(LIBFT) -Ilibft -o $(SERVER)

$(CLIENT): $(LIBFT) client.o
	@$(CC) $(CFLAGS) client.o $(LIBFT) -Ilibft -o $(CLIENT)

%.o: %.c
	@$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	@make -C libft clean
	@rm -f server.o client.o

fclean: clean
	@make -C libft fclean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re