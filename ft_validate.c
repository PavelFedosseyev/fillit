/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:28:21 by pfedosse          #+#    #+#             */
/*   Updated: 2019/07/30 00:33:16 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validate(char *str)
{
	int		i;
	int		connect;
	int		counthash;
	int		countdot;

	connect = 0;
	counthash = 0;
	countdot = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			countdot++;
		if (str[i] == '#')
		{
			counthash++;
			if (i < 19 && str[i + 1] == '#')
				connect++;
			if (i > 0 && str[i - 1] == '#')
				connect++;
			if (i < 14 && str[i + 5] == '#')
				connect++;
			if (i > 4 && str[i - 5] == '#')
				connect++;
		}
		i++;
	}
	if ((connect == 6 || connect == 8) && counthash == 4 && countdot == 12)
		return (1);
	return (0);
}
