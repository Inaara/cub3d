/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:09 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_textures(t_textures *tex)
{
	free(tex->north);
	tex->north = NULL;
	free(tex->south);
	tex->south = NULL;
	free(tex->west);
	tex->west = NULL;
	free(tex->east);
	tex->east = NULL;
}

void	free_maptab(void **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
}

static void	free_map(t_map *map)
{
	free_maptab((void **)map->tab);
}

int	free_world(t_world *world)
{
	free_textures(&world->textures);
	if (world->maptab)
		free_maptab((void **)world->maptab);
	if (world->tex)
		free_maptab((void **)world->tex);
	if (world->texture_pixels)
		free_maptab((void **)world->texture_pixels);
	free_map(&world->map);
	return (-1);
}

int	free_data(t_data *data)
{
	free(data->addr);
	data->addr = NULL;
	return (-1);
}
