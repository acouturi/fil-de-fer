/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:24:16 by acouturi          #+#    #+#             */
/*   Updated: 2018/03/07 17:36:44 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define CONFLOAT 0.7071067812
# define OFFSIZE 0

# include "biglib/lib/biglib.h"
# include <mlx.h>

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_cmpt
{
	int		i;
	int		j;
	int		k;
}				t_cmpt;

typedef struct	s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		off_x;
	int		off_y;
	double	size_y;
	double	size_x;
	t_point **points;
}				t_map;

void			ft_display(t_map map);
char			*lirefile(int fd, t_map *map);
int				keypress(int key, void *map);
void			alignemap(char **split, t_map *map);

#endif
