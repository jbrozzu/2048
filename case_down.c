/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu	  <jbrozzu@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 18:08:35 by jbrozzu           #+#    #+#             */
/*   Updated: 2014/08/17 20:23:25 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int		fonction_2(t_tab *toto, int i)
{
	int j;
	int flag;

	j = 0;
	flag = 0;
	while (j < 4)
	{
		if (toto->tab[i][j] != 0)
		{
			if (toto->tab[i + 1][j] == 0)
			{
				toto->tab[i + 1][j] = toto->tab[i][j];
				toto->tab[i][j] = 0;
				flag ++;
			}
			else if (toto->tab[i + 1][j] == toto->tab[i][j])
			{
				toto->tab[i + 1][j] *= 2;
				toto->tab[i][j] = 0;
				flag ++;
				toto->empty++;
			}
		}
		j++;
	}
	return (flag);
}

void	case_down(t_tab *toto)
{
	set_flags(toto);
	toto->flag1 = fonction_2(toto, 2);
	toto->flag2 = fonction_2(toto, 1);
	toto->flag3 = fonction_2(toto, 2);
	toto->flag4 = fonction_2(toto, 0);
	toto->flag5 = fonction_2(toto, 1);
	toto->flag6 = fonction_2(toto, 2);
	if ((toto->flag1 + toto->flag2 + toto->flag3 + toto->flag4 + toto->flag5 + toto->flag6) > 0)
		add_random(toto);
	if (toto->empty == 0)
	{
		if (check_loser(toto) == 0)
		{
			mvprintw(100, 100,"YOU LOSE !!!\n");                // DOESN'T WORK ...
			return;
		}
	}
}