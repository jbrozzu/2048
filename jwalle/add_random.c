/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:10:37 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 22:10:41 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

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
