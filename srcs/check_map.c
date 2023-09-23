/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:00 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:07 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_a_white_space(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (-1);
	else
		return (0);
}

int	check_content(t_world *world, char **map)
{
	int	i;
	int	j;

	i = 0;
	world->camera.dir = '0';
	while (i < world->map.height)
	{
		j = 0;
		while (j < world->map.width)
		{
			while (world->maptab[i][j] == ' ' || world->maptab[i][j] == '\t'
			|| world->maptab[i][j] == '\r' || world->maptab[i][j] == '\v'
			|| world->maptab[i][j] == '\f')
				j++;
			if (!(ft_strchr("201NSEW", map[i][j])))
				return (print_error("Map has invalid content"));
			if (ft_strchr("NSEW", map[i][j]) && world->camera.dir != '0')
				return (print_error("Map can only have one start"));
			if (ft_strchr("NSEW", map[i][j]) && world->camera.dir == '0')
				world->camera.dir = map[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

static int	valid_position(t_world *world, char **map)
{
	int	i;
	int	j;

	i = (int)world->camera.position.y;
	j = (int)world->camera.position.x;
	if (ft_strlen(map[i - 1]) < (size_t)j
		|| ft_strlen(map[i + 1]) < (size_t)j
		|| is_a_white_space(map[i][j - 1]) == 0
		|| is_a_white_space(map[i][j + 1]) == 0
		|| is_a_white_space(map[i - 1][j]) == 0
		|| is_a_white_space(map[i + 1][j]) == 0)
		return (-1);
	return (0);
}

static void	set_direction(t_world *world, char c)
{
	if (c == 'S')
	{
		set_vector(&world->camera.direction, 0, 1);
		set_vector(&world->camera.plane, -0.66, 0);
	}
	else if (c == 'N')
	{
		set_vector(&world->camera.direction, 0, -1);
		set_vector(&world->camera.plane, 0.66, 0);
	}
	else if (c == 'W')
	{
		set_vector(&world->camera.direction, 1, 0);
		set_vector(&world->camera.plane, 0, -0.66);
	}
	else
	{
		set_vector(&world->camera.direction, -1, 0);
		set_vector(&world->camera.plane, 0, 0.66);
	}
}

int	check_position(t_world *world, char **map)
{
	int	i;
	int	j;

	if (world->camera.dir == '0')
		return (print_error("Map doesn't have a starting position"));
	i = 0;
	while (i < world->map.height)
	{
		j = 0;
		while (j < world->map.width)
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				set_direction(world, map[i][j]);
				world->camera.position.x = (double)j + 0.5;
				world->camera.position.y = (double)i + 0.5;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (valid_position(world, map) == -1)
		return (print_error("Invalid starting position"));
	return (0);
}
