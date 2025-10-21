CC = cc

CFLAGS = -Wall -Wextra -Werror

CFILES = main.c search.c subarray.c categorizer.c

OFILES = $(CFILES:.c=.o)

NAME = rush-02

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Linking the files and producing the final rush file"
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

$(OFILES): $(CFILES)
	@echo "Compiling all .C files"
	$(CC) $(CFLAGS) -c $(CFILES)
	@echo ""
fclean: clean
	@echo "Deleteing final rush file"
	rm -f $(NAME)

clean:
	@echo "Deleteing all .O file"
	rm -f $(OFILES)
