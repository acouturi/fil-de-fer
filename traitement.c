/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:12:51 by acouturi          #+#    #+#             */
/*   Updated: 2018/03/07 16:12:29 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			alignemap(char **split, t_map *map)
{
	int k;

	k = 0;
	while (split[k])
		k++;
	k -= 1;
	while (split[k][0] == '\n' && --map->size_y)
		split[k--] = NULL;
}

int				keypress(int key, void *param)
{
	t_map *map;

	map = (t_map *)param;
	if (key == 53)
		exit(0);
	else if (key == 126)
		map->off_y -= OFFSIZE;
	else if (key == 125)
		map->off_y += OFFSIZE;
	else if (key == 124)
		map->off_x += OFFSIZE;
	else if (key == 123)
		map->off_x -= OFFSIZE;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_display(*map);
	return (1);
}

static void		ft_trace_ligne(t_point start, t_point end, t_map *map)
{
	int		i;
	float	x;
	float	y;

	i = ft_max(ft_abs(start.x - end.x), ft_abs(start.y - end.y));
	if (i == 0)
		return ;
	i++;
	x = (float)(end.x - start.x) / i;
	y = (float)(end.y - start.y) / i;
	while (i--)
	{
		if ((start.x + x * i + map->off_x) < 1000
			&& (start.x + x * i + map->off_x) > 0
			&& (start.y + y * i + map->off_y) < 1000
			&& (start.y + y * i + map->off_y) > 0)
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, (start.x + x * i
				+ map->off_x), (start.y + y * i + map->off_y), 0xFFFFFF);
	}
}

char			*lirefile(int fd, t_map *map)
{
	char		*line;
	char		*newline;
	static char	*oldline = NULL;
	int			i;

	map->size_y = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		newline = ft_strjoin(oldline, line);
		if (++map->size_y && !oldline && (newline = line) + 1)
			oldline = ft_strjoinfree(newline, " \n ");
		else
		{
			free(oldline);
			oldline = newline;
			free(line);
			oldline = ft_strjoinfree(oldline, " \n ");
		}
	}
	if (i < 0 || !oldline)
		ft_puterror("Fichier non valide");
	*ft_strrchr(oldline, '\n') = '\0';
	return (oldline);
}

void			ft_display(t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.size_y)
	{
		j = 0;
		while (j < map.size_x - 1)
		{
			ft_trace_ligne(map.points[i][j], map.points[i][j + 1], &map);
			if (i < map.size_y - 1)
				ft_trace_ligne(map.points[i][j], map.points[i + 1][j], &map);
			j++;
		}
		if (i < map.size_y - 1)
			ft_trace_ligne(map.points[i][j], map.points[i + 1][j], &map);
		i++;
	}
}
