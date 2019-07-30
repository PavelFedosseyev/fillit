/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:24:28 by pfedosse          #+#    #+#             */
/*   Updated: 2019/07/30 14:52:02 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		size_map(t_tetris *list)
{
	int			len;
	int			size;
	t_tetris	*temp;

	len = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		++len;
	}
	len = len * 4;
	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

char	**ft_collect(char *str)
{
	char	**array;
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
	int		i;

	i = 0;
	xmin = 6;
	xmax = -1;
	ymin = 6;
	ymax = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			xmin = ft_min(xmin, i % 5);
			xmax = ft_max(xmax, i % 5);
			ymin = ft_min(ymin, i / 5);
			ymax = ft_max(ymax, i / 5);
		}
		i++;
	}
	i = 0;
	array = (char **)malloc(sizeof(char *) * (ymax - ymin + 1) + 1);
	while (i < (ymax - ymin + 1))
	{
		array[i] = (char*)malloc(sizeof(char) * (xmax - xmin + 1) + 1);
		array[i] = ft_strncpy(array[i], str + (ymin + i) * 5 + xmin, xmax - xmin + 1);
		i++;
	}
	array[i] = NULL;
	return (array);
}

int		main(int ac, char **av)
{
	t_tetris	*list;
	int		fd;
	int		size;
	int		n;
	char	str[22];
	char	**mapa;
	int		old_n;

	list = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((n = (read(fd, str, 21))) > 0)
		{
			if (n != 21 && n != 20)
			{
				ft_putstr("error\n");
				return (0);
			}
			str[21] = '\0';
			if (ft_validate(str) == 1)
				list = ft_newlist(list, ft_collect(str));
			else
			{
				ft_putstr("error\n");
				return (0);
			}
			old_n = n;
		}
		if (old_n != 20)
		{
			ft_putstr("error\n");
			return (0);
		}
		size = size_map(list);
		mapa = map(size);

		while (ft_fillit(mapa, list) == 0)
			mapa = map(++size);
		print_map(mapa);
	}
	else
		ft_putstr("error\n");
	return (0);
}
