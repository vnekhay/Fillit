/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 01:42:30 by vnekhay           #+#    #+#             */
/*   Updated: 2018/01/05 18:57:31 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FALSE 0
# define TRUE 1
# define BUFFSIZE 21
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct			s_map
{
	int					x[4];
	int					y[4];
	char				name;
	struct s_map		*next;
}						t_map;

int						ft_backtrack(t_map **tmp, char **map, int i, int j);
char					**ft_map(int countf, int *size);
void					ft_check(t_map **tmp, int countf);
void					ft_freemap(char **map);
void					ft_search(char **t, int countf, t_map **tmp, int j);
int						checktermino(char *buf);
int						valid(char *file);
void					ft_vivod(char **map);

#endif
