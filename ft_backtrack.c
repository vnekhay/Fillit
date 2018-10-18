/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 01:28:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/12/28 04:06:05 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_shtodot(int i, int j, t_map **tmp, char **map)
{
	int d;

	d = 0;
	while (d < 4)
	{
		map[i + (*tmp)->y[d]][j + (*tmp)->x[d]] = '.';
		d++;
	}
	return (map);
}

char	**ft_zapis(int i, int j, t_map **tmp, char **map)
{
	int d;

	d = 0;
	while (d < 4)
	{
		map[i + (*tmp)->y[d]][j + (*tmp)->x[d]] = (*tmp)->name;
		d++;
	}
	return (map);
}

int		ft_check2(int i, int j, t_map **tmp, char **map)
{
	int x;
	int c;

	x = 0;
	c = 0;
	while (x < 4)
	{
		c += ((j + (*tmp)->x[x]) >= 0 && ((map[i + (*tmp)->y[x]])) != NULL &&
				(map[i + (*tmp)->y[x]][j + (*tmp)->x[x]] == '.'));
		x++;
	}
	if (c != 4)
		return (0);
	return (1);
}

int		ft_backtrack(t_map **tmp, char **map, int i, int j)
{
	while (map[i] != NULL && *tmp)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_check2(i, j, tmp, map) == 1)
			{
				ft_zapis(i, j, tmp, map);
				if (ft_backtrack(&((*tmp)->next), map, 0, 0) == 0)
					ft_shtodot(i, j, tmp, map);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	if (*tmp == NULL)
		return (1);
	return (0);
}
