/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:54:19 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 09:54:29 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void	clear_tab(t_tab *toto)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			toto->tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	add_random(t_tab *toto)
{
	int i;
	int j;

	i = rand() % 4;
	j = rand() % 4;
	if (toto->tab[i][j] == 0)
	{
		(((rand()) % 100) < 50) ? (toto->tab[i][j] = 2)
								: (toto->tab[i][j] = 4);
		toto->empty--;
	}
	else
		add_random(toto);
}

void	init_tab(t_tab *toto)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			toto->tab[i][j] = 0;
			j++;
		}
		i++;
	}
	add_random(toto);
	add_random(toto);
}

void	ft_game(t_tab *toto)
{
	int c;

	while ((c = getch()))
	{
		if (c == 27)
			return ;
		if (c == KEY_UP)
			case_up(toto);
		if (c == KEY_DOWN)
			case_down(toto);
		if (c == KEY_RIGHT)
			case_right(toto);
		if (c == KEY_LEFT)
			case_left(toto);
		colle00(toto);
		getmaxyx(stdscr, toto->row, toto->col);
		toto->col < toto->row ? (toto->size_board = toto->col)
								: (toto->size_board = toto->row);
		toto->x = ft_cell_size(toto->size_board);
		refresh();
	}
}

int		main(void)
{
	t_tab	toto;

	srand(time(0));
	toto.empty = 16;
	toto.x = 0;
	toto.col = 0;
	toto.row = 0;
	init_tab(&toto);
	initscr();
	start_color();
	ft_init_color();
	curs_set(0);
	getmaxyx(stdscr, toto.row, toto.col);
	keypad(stdscr, true);
	toto.col < toto.row ? (toto.size_board = toto.col)
						: (toto.size_board = toto.row);
	toto.x = ft_cell_size(toto.size_board);
	colle00(&toto);
	ft_game(&toto);
	endwin();
	return (0);
}
