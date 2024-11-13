CC = cc

NAME = server client

SV = server.c

CLT = client.c

LIBFT = ./libft/libft.a

PRINTF = ./libft/printf/libftprintf.a

LIBS = $(LIBFT) $(PRINTF)


CFLAGS = -Wall -Werror -Wextra -g

all:$(LIBS) $(NAME)

$(NAME):

server: $(SV) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SV) $(LIBFT) $(PRINTF) -o server
	
client: $(CLT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLT) $(LIBFT) $(PRINTF) -o client

$(LIBS):
	$(MAKE) -C ./libft
	$(MAKE) -C ./libft/printf

re: fclean all

clean:
	rm -f server
	rm -f client

fclean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./libft/printf fclean
	rm -f server
	rm -f client
