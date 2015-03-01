/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle	  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 18:08:35 by jwalle	           #+#    #+#             */
/*   Updated: 2014/08/17 20:23:25 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		ft_cell_size(int max)
{
	int min_cell;
	min_cell = 5;
	while ((min_cell * 4 + 5) < max - 3)
		min_cell = min_cell + 2;
	return(min_cell); 
}

void	draw_line(int x, int xa, int line)
{
	int i;

	i = 0;
	mvprintw(line * x,0, "+");
	while (i < (xa * 4))
	{
		if (i % x == 0 && i % xa == 0)
			mvprintw(line * x, i,"+");
		else
			mvprintw(line * x, i, "-");
		i++;
	}
	mvprintw(line * x, i,"+");
}

void	draw_cell(int x, int rang)
{
	int i;

	i = 0;
	while (i < (x * 4))
	{
		if (i % x != 0)
			mvprintw(i,rang * (x * 2),"|");
		i++;
	}
}

void	draw_cell_number(int x, int xa, t_tab *toto)
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while(j < 5)
		{
			(toto->tab[i - 1][j - 1] != 0) ? mvprintw(x * i - (x/2), xa * j - (xa/2),
			 "%d", toto->tab[i - 1][j - 1]) : mvprintw(x * i - (x/2), xa * j - (xa/2),
			  " ");
			j++;
		}
		i++;
	}
}

void	colle00(int x, int row, int col, t_tab *toto)
{
	int line;
	int rang;
	int xa;

	clear();
	xa = x * 2;
	line = 0;
	while (line < 5)
	{
		draw_line(x, xa, line);
		line++;
	}
	rang = 0;
	while(rang < 5)
	{
		draw_cell(x, rang);
		rang++;
	}
	draw_cell_number(x, xa, toto);		
	printf("%d, %d", row, col);

}

/*void	colle00(int x, int y)
{
	int		cn[2];
	int		middle;

	middle = (x / 2);
	cn[1] = -1;
	while (++cn[1] < y)
	{
		cn[0] = -1;
		while (++cn[0] < x)
		{
			ft_putstr(BLUE_BG);
			if ((!cn[0] && !cn[1] ) || (cn[1] == y - 1 && cn[0] == x - 1))
				ft_putchar('+');
			else if ((cn[0] == x - 1 && !cn[1]) ||(cn[1] == y - 1 && !cn[0]))
				ft_putchar('+');
			else if (cn[0] == middle && cn[1] == middle)
				ft_putstr("1");
			else if (cn[1] > 0 && cn[1] < y - 1 && cn[0] > 0 && cn[0] < x - 1)
				ft_putstr(" ");
			else if ((!cn[0] || cn[0] == x - 1) && cn[1] > 0 && cn[1] < y - 1)
				ft_putchar('|');
			else
				ft_putchar('-');
		}
		ft_putstr(RESET);
		ft_putchar('\n');
	}
}*/