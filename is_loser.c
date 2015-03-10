/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_loser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:47:51 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 23:40:13 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int	check_loser(t_tab *toto)
{
	int i;
	int j;

	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 3)
		{
			if (toto->tab[i][j] == toto->tab[i][j + 1])
				return (1);
		}
	}
	j = 0;
	while (j++ < 4)
	{
		i = 0;
		while (i++ < 3)
		{
			if (toto->tab[i][j] == toto->tab[i + 1][j])
				return (1);
		}
	}
	return (0);
}

int			is_loser(t_tab *toto)
{
	if (check_loser(toto) == 0)
	{
		mvprintw(toto->row - 4, 5, "YOU LOSE !!!");
		refresh();
		usleep(1000000);
		return (1);
	}
	return (0);
}
