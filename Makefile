NAME = game_2048

SRC = ft_game.c ft_draw.c case_left.c case_right.c case_up.c case_down.c check_loser.c

OBJ = ft_game.o ft_draw.o case_left.o case_right.o case_up.o case_down.o check_loser.o

all : $(NAME)

$(NAME) :
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ $(SRC) -lncurses
	gcc -o $(NAME) $(OBJ) -L libft/ -lft -lncurses

clean:
	/bin/rm -f $(OBJ)
fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: fclean all