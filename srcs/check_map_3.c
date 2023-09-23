/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:00 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:07 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_surrounded(t_world *world)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < world->map.height)
	{
		j = 0;
		while (j < world->map.width)
		{
			if (world->maptab[i][j] == '2')
			{
				if (is_zero(world, i - 1, j) || is_zero(world, i, j - 1)
					|| is_zero(world, i + 1, j) || is_zero(world, i, j + 1))
					return (false);
			}
			j++;
		}
		i++;
	}
	if (left_right_side(world))
		return (false);
	return (true);
}

int	check_map(t_world *world, char **map)
{
	if (!world->maptab)
		return (print_error("Map was not created"));
	if (world->map.height < 3)
		return (print_error("Map has invalid height"));
	if (world->map.width < 3)
		return (print_error("Map has invalid width"));
	if (is_surrounded(world) == false)
		return (print_error("Map is not surrounded by walls"));
	if (has_empty_line(world) == true)
		return (print_error("Map is split by empty line"));
	if (check_content(world, map) == -1)
		return (-1);
	if (check_position(world, map) == -1)
		return (-1);
	if (check_map_position(&world->map) == -1)
		return (print_error("Map is not located at the end of file"));
	return (0);
}
