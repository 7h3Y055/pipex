NAME = pipex
BONUS = pipex_bonus
SRCS = pipex.c utilis.c utilis2.c
SRCSB = pipex_bonus.c pipex_bonus_utilis_0.c pipex_bonus_utilis_1.c 
CFLAGS = -Wall -Werror -Wextra
libft = ./libft/libft.a


all:$(libft) $(NAME)

$(libft):
	make -C ./libft/

$(NAME): $(libft)
	gcc $(SRCS) $(libft) $(CFLAGS) -o $(NAME)

bonus:$(libft) $(BONUS)

$(BONUS):
	gcc $(CFLAGS) $(SRCSB) $(libft) -o $(BONUS)

clean:
	make clean -C ./libft/

fclean:
	make fclean -C ./libft/
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all
