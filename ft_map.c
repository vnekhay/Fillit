/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 01:28:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/12/28 04:19:02 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_mapdot(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_map(int countf, int *size)
{
	char	**map;
	int		i;
	int		temp;

	i = 0;
	temp = countf * 4;
	while (*size * *size < temp)
		*size += 1;
	if (!(map = (char**)malloc(sizeof(char*) * (*size + 5))))
		return (NULL);
	while (i < *size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (*size + 5))))
			return (NULL);
		i++;
	}
	return (ft_mapdot(map, *size));
}
