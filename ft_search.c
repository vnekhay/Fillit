/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 01:28:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/12/28 04:24:25 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_addtolist(char **t, t_map **tetr, int n)
{
	int		i;
	int		j;
	int		d;

	i = 0;
	j = 0;
	d = 0;
	(*tetr)->next = (t_map*)malloc(sizeof(t_map));
	*tetr = (*tetr)->next;
	while (t[i][j] != '\0')
	{
		if (t[i][j] == '#')
		{
			t[i][j] = 'A' + n;
			(*tetr)->name = 'A' + n;
			(*tetr)->y[d] = j / 5;
			(*tetr)->x[d] = j % 5;
			d++;
		}
		j++;
	}
}

static void	writeinmas(char **t, int countf, t_map *tetr)
{
	int		n;
	int		k;

	n = 0;
	k = 1;
	while (k != countf)
	{
		t++;
		n++;
		ft_addtolist(t, &tetr, n);
		k++;
	}
	tetr->next = NULL;
}

void		ft_search(char **t, int countf, t_map **tmp, int j)
{
	t_map	*tetr;
	int		i;
	int		d;
	int		n;

	i = 0;
	n = 0;
	d = 0;
	tetr = malloc(sizeof(t_map));
	while (t[i][j] != '\0')
	{
		if (t[i][j] == '#')
		{
			tetr->y[d] = j / 5;
			tetr->x[d] = j % 5;
			tetr->name = 'A' + n;
			tetr->next = NULL;
			if (*tmp == NULL)
				*tmp = tetr;
			d++;
		}
		j++;
	}
	writeinmas(t, countf, tetr);
	tetr = *tmp;
}
