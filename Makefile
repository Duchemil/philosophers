CC = gcc -g3 -pthread # -fsanitize=thread
CFLAGS = -Wall -Werror -Wextra
SRC = src/main.c src/utils.c src/init.c src/actions.c src/threads.c src/checks.c
OBJ = $(SRC:.c=.o)
NAME = philosophers

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
