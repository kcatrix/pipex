CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra

SRC = $(wildcard ./src/*.c)

NAME = pipex

OBJ = $(SRC:.c=.o)

all: $(NAME)

LIBFT = ./libft/libft.a

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $(SRC) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re