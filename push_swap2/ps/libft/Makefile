CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

CFILES = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atol.c ft_isalpha.c \
		ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c	ft_striteri.c\
		ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
		ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
		ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

OFILES = $(CFILES:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all : $(NAME)

bonus: $(OFILES) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OFILES) $(BONUS_OBJS)


$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Deleting all files ."
	@rm -f $(OFILES) $(BONUS_OBJS)

fclean: clean
	@echo "Deleting libft.a .."
	@rm -f $(NAME)

re: fclean all
	@echo "Project rebuilt ..."

.PHONY: all clean fclean re bonus
