/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:19:43 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/01 10:19:47 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H

# include "libft.h"
# include <unistd.h>
# include <curses.h>
# include <stdlib.h>
# include <time.h>

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_tab
{
	int			tab[4][4];
	int			empty;
	int			size_board;
	int			x;
	int			col;
	int			row;
}				t_tab;

typedef struct	s_flag
{
	int			flag1;
	int			flag2;
	int			flag3;
	int			flag4;
	int			flag5;
	int			flag6;
	int			flag_last1;
	int			flag_last2;
	int			flag_last3;
	int			flag_last4;
	int			flag_last5;
	int			tmp;
}				t_flag;

void			print_cell(int nb);
void			ft_draw(t_tab *toto);
int				ft_cell_size(int max);
void			case_up(t_tab *toto);
void			case_down(t_tab *toto);
void			case_right(t_tab *toto);
void			case_left(t_tab *toto);
void			add_random(t_tab *toto);
void			set_flags(t_flag *titi);
int				is_loser(t_tab *toto);

#endif
