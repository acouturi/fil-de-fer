/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:52:03 by acouturi          #+#    #+#             */
/*   Updated: 2018/03/07 16:02:11 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	remp_map(t_map *map, char *split, int j, int k)
{
	double	cnst;
	double	tmp;
	t_point *coor;
	t_point center;

	if (!(ft_isdigit(split[0])) && split[0] != '-')
		ft_puterror("map non valide");
	cnst = (1000 * CONFLOAT / ft_max(map->size_x, map->size_y));
	center = (t_point){.x = (1000 - (map->size_x - 1) * cnst) / 2,
		.y = (1000 - (map->size_y - 1) * cnst) / 2};
	coor = &map->points[j][k];
	coor->x = cnst * k;
	coor->y = cnst * j;
	coor->x -= ((map->size_x - 1) * cnst) / 2;
	coor->y -= ((map->size_y - 1) * cnst) / 2;
	tmp = coor->y;
	coor->y = coor->x * CONFLOAT + tmp * CONFLOAT;
	coor->x = coor->x * CONFLOAT + tmp * -CONFLOAT;
	coor->y = coor->y * CONFLOAT - (double)ft_atoi(split) * 3;
	coor->x += ((map->size_x - 1) * cnst) / 2 + center.x;
	coor->y += ((map->size_y - 1) * cnst) / 2 + center.y;
}

static char	**allocpoints(t_map *map, char *oldline)
{
	char	**split;
	int		col;

	col = 0;
	if (!(map->points = (t_point **)malloc(sizeof(t_point *) *
		(map->size_y))))
		ft_puterror("error alloc");
	if (!(split = ft_strsplit(oldline, ' ')) || split[0] == 0)
		ft_puterror("map non valide");
	while (split[col] && ft_strncmp(split[col], "\n", 1) != 0)
		col++;
	if (ft_strncmp(split[col - 1], "\n", 1) == 0)
		ft_puterror("map non valide");
	if (!(map->points[0] = (t_point *)malloc(sizeof(t_point) * col)))
		ft_puterror("error alloc");
	map->size_x = col;
	return (split);
}

static char	*checkfile(int argc, char **argv, t_map *map)
{
	int		fd;
	char	*oldline;

	if (argc != 2)
		ft_puterror("Usage: fdf filename");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_puterror("Fichier non valide");
	oldline = lirefile(fd, map);
	close(fd);
	return (oldline);
}

static void	verifmap(t_cmpt *compt, int *k, t_map *map, char **split)
{
	int		col;

	compt->i++;
	compt->j++;
	col = 0;
	while (ft_strncmp(split[col], "\n", 1) != 0)
		col++;
	if (!(map->points[compt->j] = (t_point *)malloc(sizeof(t_point) * col)))
		ft_puterror("error alloc");
	if (col != *k)
		ft_puterror("map non valide");
	*k = 0;
}

int			main(int argc, char **argv)
{
	char	*oldline;
	t_map	map;
	char	**split;
	t_cmpt	compt;

	compt = (t_cmpt){.i = -1, .j = 0, .k = -1};
	ft_bzero(&map, sizeof(t_map));
	oldline = checkfile(argc, argv, &map);
	split = allocpoints(&map, oldline);
	free(oldline);
	alignemap(split, &map);
	while ((++compt.k) + 1 && (++compt.i) + 1 && split[compt.i])
	{
		if (ft_strcmp(split[compt.i], "\n") == 0)
			verifmap(&compt, &compt.k, &map, split);
		split[compt.i] ? remp_map(&map, split[compt.i], compt.j, compt.k) : 42;
	}
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 1000, 1000,
		ft_strjoin("FdF - ", argv[1]));
	ft_display(map);
	mlx_hook(map.win_ptr, 2, 3, keypress, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
