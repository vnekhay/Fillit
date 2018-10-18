/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 01:28:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/12/28 04:34:21 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**execute(char **t, int countf)
{
	char	**map;
	t_map	*tmp;
	int		size;

	tmp = NULL;
	size = 2;
	ft_search(t, countf, &tmp, 0);
	ft_check(&tmp, countf);
	map = ft_map(countf, &size);
	while (ft_backtrack(&tmp, map, 0, 0) == 0)
	{
		ft_freemap(map);
		size++;
		map = ft_map(countf, &size);
	}
	return (map);
}

void		charsedsuka(int gavno)
{
	if (gavno == 1)
	{
		ft_putendl("error");
		exit(0);
	}
}

void		shitfunction(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

int			file_read(int fd, char *buf, char **t)
{
	int	d;
	int	countf;
	int	count;
	int charsred;

	shitfunction(&d, &countf, &count, &charsred);
	while ((count = read(fd, buf, BUFFSIZE - 1)))
	{
		charsred += count;
		if (count < BUFFSIZE - 1 || checktermino(buf) == FALSE)
			return (0);
		t[d] = ft_strsub(buf, 0, 20);
		if (t[d] == NULL)
			return (FALSE);
		if ((count = read(fd, buf, 1)))
			if (buf[0] != '\n')
				return (0);
		charsred = count;
		countf++;
		d++;
	}
	charsedsuka(charsred);
	return (countf);
}

int			valid(char *file)
{
	int		fd;
	char	*buf;
	char	**t;
	int		countf;

	countf = 0;
	buf = ft_strnew(BUFFSIZE);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if ((t = (char **)malloc(sizeof(*t) * (26))) == NULL)
		return (FALSE);
	if ((countf = file_read(fd, buf, t)) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	ft_vivod(execute(t, countf));
	close(fd);
	return (0);
}
