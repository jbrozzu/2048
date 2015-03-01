/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrozzu	  <jbrozzu@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/03 18:08:35 by jbrozzu           #+#    #+#             */
/*   Updated: 2014/08/17 20:23:25 by jbrozzu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

static int		fonction_2(t_flag *titi, t_tab *toto, int j)
{
	int i;
	int flag;

	titi->tmp = 0;
	i = 0;
	flag = 0;
	while (i < 4)
	{
		if (toto->tab[i][j] != 0)
		{
			if (toto->tab[i][j - 1] == 0)
			{
				toto->tab[i][j - 1] = toto->tab[i][j];
				toto->tab[i][j] = 0;
				flag++;
			}
			else if (toto->tab[i][j - 1] == toto->tab[i][j])
			{
				toto->tab[i][j - 1] *= 2;
				toto->tab[i][j] = 0;
				flag++;
				toto->empty++;
				titi->tmp++;
			}
		}
		i++;
	}
	return (flag);
}

static int		fonction_3(t_tab *toto, int j)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (i < 4)
	{
		if (toto->tab[i][j] != 0)
		{
			if (toto->tab[i][j - 1] == 0)
			{
				toto->tab[i][j - 1] = toto->tab[i][j];
				toto->tab[i][j] = 0;
				flag ++;
			}
		}
		i++;
	}
	return (flag);
}

void	case_left(t_tab *toto)
{
	t_flag	titi;

	set_flags(&titi);
	titi.flag1 = fonction_2(&titi, toto, 1);
	titi.flag_last1 = titi.tmp;
	titi.flag2 = fonction_2(&titi, toto, 2);
	titi.flag_last2 = titi.tmp;
	titi.tmp = 0;
	titi.flag3 = (titi.flag_last1 == 0 ? (fonction_2(&titi, toto, 1)) : (fonction_3(toto, 1)));
	titi.flag_last3 = titi.tmp;
	titi.flag4 = fonction_2(&titi, toto, 3);
	titi.flag_last4 = titi.tmp;
	titi.tmp = 0;
	titi.flag5 = ((titi.flag_last2 == 0 && titi.flag_last4 == 0) ? (fonction_2(&titi, toto, 2)) : (fonction_3(toto, 2)));
	titi.flag_last5 = titi.tmp;
	titi.flag6 = ((titi.flag_last1 == 0 && titi.flag_last3 == 0 && titi.flag_last5 == 0) ? (fonction_2(&titi, toto, 1)) : (fonction_3(toto, 1)));
	if ((titi.flag1 + titi.flag2 + titi.flag3 + titi.flag4 + titi.flag5 + titi.flag6) > 0)
		add_random(toto);
	if (toto->empty == 0)
	{
		if (check_loser(toto) == 0)
		{
			mvprintw(100, 100,"YOU LOSE !!!\n");                  // DOESN'T WORK ...
			return;
		}
	}
}