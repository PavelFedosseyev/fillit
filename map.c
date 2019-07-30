/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:44:09 by pfedosse          #+#    #+#             */
/*   Updated: 2019/07/29 23:05:01 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**map(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
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
