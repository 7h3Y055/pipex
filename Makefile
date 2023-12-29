NAME = pipex
BONUS = pipex_bonus
SRCS = pipex.c utilis0.c utilis1.c
SRCSB = pipex_bonus.c pipex_bonus_utilis_0.c pipex_bonus_utilis_1.c
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT)
	gcc $(SRCS) $(CFLAGS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(LIBFT)
	gcc $(SRCSB) $(CFLAGS) $(LIBFT) -o $(BONUS)

clean:
	make clean -C ./libft

fclean:
	make fclean -C ./libft
	rm -f $(NAME) $(BONUS)

re:fclean all


