NAME = pipex
SRCS = pipex.c utilis.c utilis2.c
CFLAGS = -Wall -Werror -Wextra
libft = ./libft/libft.a


all:$(libft) $(NAME)

$(libft):
	make -C ./libft/

$(NAME): $(libft)
	gcc $(SRCS) $(libft) $(CFLAGS) -o $(NAME)

clean:
	make clean -C ./libft/

fclean:
	make fclean -C ./libft/
	rm -rf $(NAME)

re: fclean all
