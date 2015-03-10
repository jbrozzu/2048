/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:44:17 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 22:44:19 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void		clear_tab(t_tab *toto)
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

static void		ft_init_color(void)
{
	init_color(COLOR_RED, 500, 300, 200);
	init_color(COLOR_MAGENTA, 304, 200, 209);
	init_color(COLOR_CYAN, 304, 222, 100);
	init_color(COLOR_WHITE, 155 * 4, 160 * 4, 160 * 4);
	init_pair(1, COLOR_RED, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(16, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(32, COLOR_BLACK, COLOR_CYAN);
	init_pair(64, COLOR_YELLOW, COLOR_CYAN);
	init_pair(128, COLOR_RED, COLOR_CYAN);
	init_pair(256, COLOR_MAGENTA, COLOR_RED);
	init_pair(512, COLOR_YELLOW, COLOR_BLACK);
	init_pair(1024, COLOR_YELLOW, COLOR_GREEN);
	init_pair(2048, COLOR_YELLOW, COLOR_WHITE);
}

static void		init_tab(t_tab *toto)
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

void			ft_game(t_tab *toto)
{
	int c;

	while ((c = getch()))
	{
		if (c == 27)
			return ;
		if (toto->empty == 0 && is_loser(toto))
			return ;
		if (c == KEY_UP)
			case_up(toto);
		if (c == KEY_DOWN)
			case_down(toto);
		if (c == KEY_RIGHT)
			case_right(toto);
		if (c == KEY_LEFT)
			case_left(toto);
		ft_draw(toto);
		getmaxyx(stdscr, toto->row, toto->col);
		toto->col < toto->row ? (toto->size_board = toto->col)
								: (toto->size_board = toto->row);
		toto->x = ft_cell_size(toto->size_board);
		refresh();
	}
}

int				main(void)
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
	COLOR_PAIRS = 2049;
	ft_init_color();
	curs_set(0);
	getmaxyx(stdscr, toto.row, toto.col);
	keypad(stdscr, true);
	toto.col < toto.row ? (toto.size_board = toto.col)
						: (toto.size_board = toto.row);
	toto.x = ft_cell_size(toto.size_board);
	ft_draw(&toto);
	ft_game(&toto);
	endwin();
	clear_tab(&toto);
	return (0);
}
