NAME = 2048

all : $(NAME)

$(NAME) :
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ *.c -lncurses
	gcc -o $(NAME) -g *.o -L libft/ -lft -lncurses

clean:
	/bin/rm -f *.o
fclean:
	/bin/rm -f *.o
	/bin/rm -f $(NAME)

re: fclean all
