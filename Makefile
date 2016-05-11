NAME = game_2048

SRC = ft_game.c ft_draw.c case_left.c \
		case_right.c case_up.c case_down.c \
		is_loser.c cell_size.c add_random.c \
		set_flags.c

OBJ = ft_game.o ft_draw.o case_left.o \
		case_right.o case_up.o case_down.o \
		is_loser.o cell_size.o add_random.o \
		set_flags.o

all : $(NAME)

$(NAME) :
	make -C libft/ fclean
	make -C libft/
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft -lncurses

clean:
	/bin/rm -f $(OBJ)
fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: fclean all
