/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:57:47 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 09:57:50 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static void		draw_line(t_tab *toto, int xa, int line)
{
	int i;

	i = 0;
	mvprintw(line * toto->x, 0, "+");
	while (i < (xa * 4))
	{
		if (i % toto->x == 0 && i % xa == 0)
			mvprintw(line * toto->x, i, "+");
		else
			mvprintw(line * toto->x, i, "-");
		i++;
	}
	mvprintw(line * toto->x, i, "+");
}

static void		draw_cell(t_tab *toto, int rang)
{
	int i;

	i = 0;
	while (i < (toto->x * 4))
	{
		if (i % toto->x != 0)
			mvprintw(i, rang * (toto->x * 2), "|");
		i++;
	}
}

static void		draw_color(int n, t_tab *toto, int i, int j)
{
	int x;
	int y;
	int xa;

	x = 0;
	xa = toto->x * 2;
	while (x < xa)
	{
		y = 0;
		while (y < toto->x)
		{
			attron(COLOR_PAIR(n));
			mvprintw(i + y, j + x, " ");
			attroff(COLOR_PAIR(n));
			y++;
		}
		x++;
	}
}

static void		draw_cell_number(int xa, t_tab *toto)
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			draw_color(toto->tab[i - 1][j - 1], toto,
				(toto->x * i - toto->x + 1), (xa * j - (xa * 2)) + xa);
			attron(COLOR_PAIR(toto->tab[i - 1][j - 1]));
			attron(A_BOLD);
			(toto->tab[i - 1][j - 1] != 0) ?
			mvprintw(toto->x * i - (toto->x / 2), xa * j - (xa / 2),
			"%d", toto->tab[i - 1][j - 1]) :
			mvprintw(toto->x * i - (toto->x / 4), xa * j - (xa / 2), " ");
			attroff(COLOR_PAIR(toto->tab[i - 1][j - 1]));
			attroff(A_BOLD);
			if (toto->tab[i - 1][j - 1] >= WIN_VALUE)
				mvprintw(toto->row - 5, 5, "YOU WIN !");
			j++;
		}
		i++;
	}
}

void			ft_draw(t_tab *toto)
{
	int line;
	int rang;
	int xa;

	clear();
	xa = toto->x * 2;
	line = 0;
	draw_cell_number(xa, toto);
	attron(COLOR_PAIR(2));
	while (line < 5)
	{
		draw_line(toto, xa, line);
		line++;
	}
	rang = 0;
	while (rang < 5)
	{
		draw_cell(toto, rang);
		rang++;
	}
	attroff(COLOR_PAIR(2));
}
