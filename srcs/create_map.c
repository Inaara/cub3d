/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:01 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	lines_counter(t_world *world, char **map, int i)
{
	int	ind;

	ind = i;
	while (map[i] && ft_strncmp(map[i], "\n", 2))
		i++;
	world->map.end = i;
	return (i - ind);
}

int	fill_tab_bis(t_map *map, char **maptab, int i, int k)
{
	int	l;

	l = 0;
	while (map->tab[i][l] && map->tab[i][l] != '\n')
	{
		if (ft_strchr("01NSEW", map->tab[i][l]))
			maptab[k][l] = map->tab[i][l];
		else if (map->tab[i][l] == ' ' || map->tab[i][l] == '\t'
			|| map->tab[i][l] == '\r'
		|| map->tab[i][l] == '\v' || map->tab[i][l] == '\f')
			maptab[k][l] = '1';
		else if (map->tab[i][l] == '\0')
			maptab[k][l] = '2';
		else
			return (print_error("Invalid character in the map"));
		l++;
	}
	return (0);
}

static int	fill_tab(t_map *map, char **maptab, int i)
{
	int	k;
	int	l;

	map->width = get_max_len(map, i);
	k = 0;
	while (k < map->height)
	{
		l = 0;
		maptab[k] = malloc(sizeof(char) * (map->width + 1));
		while (l < map->width)
			maptab[k][l++] = '2';
		if (!maptab[k])
			return (print_error("Couldn't allocate the tab"));
		if (fill_tab_bis(map, maptab, i, k) == -1)
			return (-1);
		while (l < map->width)
			maptab[k][l++] = '2';
		maptab[k][l] = '\0';
		k++;
		i++;
	}
	maptab[k] = NULL;
	return (0);
}

static int	malloc_map(t_world *world, char **map, int i)
{
	world->map.height = lines_counter(world, map, i);
	world->maptab = malloc(sizeof(char *) * (world->map.height + 1));
	if (!world->maptab)
		return (print_error("Couldn't allocate the tab"));
	if (fill_tab(&world->map, world->maptab, i) == -1)
		return (-1);
	return (0);
}

int	create_map(t_world *world, char **map, int k)
{
	if (malloc_map(world, map, k) == -1)
		return (-1);
	space_to_wall(world);
	return (0);
}
