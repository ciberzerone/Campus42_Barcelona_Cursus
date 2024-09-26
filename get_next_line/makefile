NAME = get_next_line

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -D BUFFER_SIZE=42 -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
