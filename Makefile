NAME = tcaps

CC = gcc

SRC = ./termcaps.c

OBJ = $(SRC:.c=.o)

INC = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
#	@(echo "\x1bObject files compiled.\x1b[0m")
	@($(CC) -o $(NAME) $(OBJ) $(INC))
	@(echo "\x1b[32m$(NAME)\x1b[0m")
	@(/bin/rm -f $(OBJ))

%.o: %.c
	@($(CC) -o $@ -c $<)

clean:
	@(/bin/rm -f $(OBJ))
	@(echo "\x1b[31mClean\x1b[0m")

fclean: clean
	@(/bin/rm -f $(NAME))
	@(echo "\x1b[31$(NAME)\x1b[0m")

re: fclean all
