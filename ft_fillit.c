/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:05:02 by pfedosse          #+#    #+#             */
/*   Updated: 2019/07/30 00:33:24 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**addorclean(char **map, t_tetris *list, int x, int y, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (list->data[i])
	{
		j = 0;
		while (list->data[i][j])
		{
			if (list->data[i][j] != '.')
			{
				if (flag == 1)
					map[x + i][y + j] = list->symbol;
				if (flag == 0)
					map[x + i][y + j] = '.';
			}
			j++;
		}
		i++;
	}
	return (map);
}

int		ft_try(char **map, char **tetr, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(tetr[i])
	{
		if (map[x + i] == 0)
			return (-1);
		j = 0;
		while (tetr[i][j])
		{
			if (map[x + i][y + j] == 0)
				return (-1);
			if (tetr[i][j] != '.' && map[x + i][y + j] != '.')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_fillit(char **mapa, t_tetris *list)
{
	int		x;
	int		y;


	x = 0;
	if (!list)
		return (1);
	while (mapa[x])
	{
		y = 0;
		while(mapa[x][y])
		{
			if (ft_try(mapa, list->data, x, y) == 1)
			{
				mapa = addorclean(mapa, list, x, y, 1);
				if (ft_fillit(mapa, list->next) == 0)
					mapa = addorclean(mapa, list, x, y, 0);
				else
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
