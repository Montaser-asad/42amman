CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

PRINTF_DIR = printf

CFILES = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
		ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_striteri.c \
		ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
		ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
		ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c

PRINTF_OBJS = $(PRINTF_DIR)/ft_putstr.o $(PRINTF_DIR)/ft_putnbr.o \
		$(PRINTF_DIR)/ft_puthex.o $(PRINTF_DIR)/ft_printf.o $(PRINTF_DIR)/ft_putptr.o

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bouns.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OFILES = $(CFILES:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) printf_objs
	@ar rcs $(NAME) $(OFILES) $(PRINTF_OBJS)

printf_objs:
	@make -C $(PRINTF_DIR)

bonus: $(OFILES) $(BONUS_OBJS) printf_objs
	@ar rcs $(NAME) $(OFILES) $(BONUS_OBJS) $(PRINTF_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OFILES) $(BONUS_OBJS)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus printf_objs
