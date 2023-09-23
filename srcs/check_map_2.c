/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:00 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:07 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	up_down_side(t_world *world, int i, int j)
{
	if (!world->maptab)
		return (-1);
	while (j < world->map.width)
	{
		if (world->maptab[i][j] != '1' && world->maptab[i][j] != '2')
			return (-1);
		j++;
	}
	return (0);
}

int	left_right_side(t_world *world)
{
	int	i;
	int	j;

	if (up_down_side(world, 0, 0) == -1)
		return (-1);
	i = 1;
	while (i < (world->map.height - 1))
	{
		j = ft_strlen(world->maptab[i]) - 1;
		if (world->maptab[i][0] != '1' && world->maptab[i][0] != '2')
			return (-1);
		if (world->maptab[i][j] != '1' && world->maptab[i][j] != '2')
			return (-1);
		i++;
	}
	if (up_down_side(world, i, 0) == -1)
		return (-1);
	return (0);
}

int	check_map_position(t_map *map)
{
	int	i;
	int	j;

	i = map->end;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] != ' ' && map->tab[i][j] != '\t'
				&& map->tab[i][j] != '\r' && map->tab[i][j] != '\n'
				&& map->tab[i][j] != '\v' && map->tab[i][j] != '\f')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	is_zero(t_world *world, int i, int j)
{
	if (i < 0 || j < 0)
		return (false);
	if (i >= world->map.height || world->map.width <= j)
		return (false);
	if (ft_strchr("0NSEW", world->maptab[i][j]))
		return (true);
	return (false);
}

bool	has_empty_line(t_world *world)
{
	int		i;
	int		j;
	bool	has_only_two;

	i = 0;
	while (i < world->map.height)
	{
		j = 0;
		has_only_two = true;
		while (j < world->map.width)
		{
			if (world->maptab[i][j] != '2')
				has_only_two = false;
			j++;
		}
		if (has_only_two)
			return (true);
		i++;
	}
	return (false);
}
