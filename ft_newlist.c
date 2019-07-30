/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:43:22 by pfedosse          #+#    #+#             */
/*   Updated: 2019/07/30 00:00:49 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

t_tetris		*ft_newlist(t_tetris *list, char **array)
{
	t_tetris	*new;
	t_tetris	*tmp;

	new = (t_tetris *)malloc(sizeof(t_tetris));
	new->data = array;
	new->next = NULL;
	if (!list)
	{
		new->symbol = 'A';
		return new;
	}
	tmp = list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->symbol = tmp->symbol + 1;
	return (list);
}

