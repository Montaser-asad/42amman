CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SERVER = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	@make -C libft bonus

${SERVER_BONUS}: $(LIBFT) server_bonus.o
	@$(CC) $(CFLAGS) server_bonus.o $(LIBFT) -Ilibft -o $(SERVER_BONUS)

$(SERVER): $(LIBFT) server.o
	@$(CC) $(CFLAGS) server.o $(LIBFT) -Ilibft -o $(SERVER)

$(CLIENT_BONUS): $(LIBFT) client_bonus.o
	@$(CC) $(CFLAGS) client_bonus.o $(LIBFT) -Ilibft -o $(CLIENT_BONUS)

$(CLIENT): $(LIBFT) client.o
	@$(CC) $(CFLAGS) client.o $(LIBFT) -Ilibft -o $(CLIENT)

%.o: %.c
	@$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	@make -C libft clean
	@rm -f server.o client.o server_bonus.o client_bonus.o

fclean: clean
	@make -C libft fclean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re