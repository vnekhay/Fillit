/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 01:28:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/12/28 04:11:51 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_checklarg(t_map *tmp2, int x, int y, int d)
{
	while (d != -1)
	{
		if (tmp2->x[d] <= x)
			x = tmp2->x[d];
		if (tmp2->y[d] <= y)
			y = tmp2->y[d];
		d--;
	}
	d = -1;
	while (++d < 4)
	{
		tmp2->x[d] = tmp2->x[d] - x;
		tmp2->y[d] = tmp2->y[d] - y;
	}
}

void	ft_check(t_map **tmp, int countf)
{
	t_map	*tmp2;
	int		x;
	int		y;
	int		d;

	tmp2 = *tmp;
	while (countf != 0)
	{
		d = 3;
		x = 3;
		y = 3;
		ft_checklarg(tmp2, x, y, d);
		tmp2 = tmp2->next;
		countf--;
	}
}
