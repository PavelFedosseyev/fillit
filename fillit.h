/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:08:31 by pfedosse          #+#    #+#             */
/*   Updated: 2019/07/30 00:33:18 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# define ft_max(a, b) (a > b ? a : b)
# define ft_min(a, b) (a < b ? a : b)


typedef struct		s_ftft
{
	char **data;
}					t_ftft;


typedef struct		s_tetris
{
	char			**data;
	char			symbol;
	struct s_tetris	*next;

}					t_tetris;

char				**map(int size);
int					ft_fillit(char **mapa, t_tetris *list);
void				print_map(char **map);
t_tetris			*ft_newlist(t_tetris *list, char **array);
int					size_map(t_tetris *list);
int					ft_validate(char *str);

#endif
