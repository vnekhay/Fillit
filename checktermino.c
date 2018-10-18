/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 01:28:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/12/28 03:23:47 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validchars(char c)
{
	if (c == '#' || c == '.' || c == '\n')
		return (1);
	return (0);
}

static int	cntflag(char *buf, int i)
{
	int		flag;

	flag = 0;
	if (buf[i + 1] == '#')
		flag++;
	if (buf[i + 5] == '#')
		flag++;
	if (buf[i - 1] == '#')
		flag++;
	if (buf[i - 5] == '#')
		flag++;
	return (flag);
}

int			checktermino(char *buf)
{
	int		i;
	int		dots;
	int		flags;

	flags = 0;
	i = 0;
	dots = 0;
	while ((validchars(buf[i])) == 1)
	{
		if (buf[i] == '#')
			flags += cntflag(buf, i);
		if (buf[i] == '.')
			dots++;
		if (i == 4 || i == 9 || i == 14 || i == 19)
			if (buf[i] != '\n')
				return (FALSE);
		i++;
	}
	if (dots != 12 || (flags != 6 && flags != 8))
		return (FALSE);
	return (TRUE);
}
