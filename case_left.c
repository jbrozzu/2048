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

static int		fonction_2(t_tab *toto, int j)
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
				flag += 1;
			}
			else if (toto->tab[i][j - 1] == toto->tab[i][j])
			{
				toto->tab[i][j - 1] *= 2;
				toto->tab[i][j] = 0;
				flag += 1;
			}
		}
		i++;
	}
	return (flag);
}

void	case_left(t_tab *toto)
{
	set_flags(toto);
	toto->flag1 = fonction_2(toto, 1);
	toto->flag2 = fonction_2(toto, 2);
	toto->flag3 = fonction_2(toto, 1);
	toto->flag4 = fonction_2(toto, 3);
	toto->flag5 = fonction_2(toto, 2);
	toto->flag6 = fonction_2(toto, 1);
	if ((toto->flag1 + toto->flag2 + toto->flag3 + toto->flag4 + toto->flag5 + toto->flag6) > 0)
		add_random(toto);
}