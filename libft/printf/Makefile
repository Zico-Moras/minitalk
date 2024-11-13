CC = cc
FLAGS = -Wall -Wextra -Werror -I.
DEPS = ft_printf.h

SRC = $(shell find . ../ -type f -name '*.c')
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
