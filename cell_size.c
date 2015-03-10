/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:36:11 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 21:36:32 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		ft_cell_size(int max)
{
	int min_cell;

	min_cell = 5;
	while ((min_cell * 4 + 5) < max - 5)
		min_cell = min_cell + 2;
	return (min_cell);
}
