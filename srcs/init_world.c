/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:09 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_window(t_window *window)
{
	window->reference = NULL;
	set_vector(&window->size, SCREEN_WIDTH, SCREEN_HEIGHT);
}

static void	init_camera(t_camera *camera)
{
	set_vector(&camera->position, 0.0, 0.0);
	set_vector(&camera->direction, 0.0, 0.0);
	set_vector(&camera->plane, 0.0, 0.0);
}

static void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	set_color(&textures->floor, -1, -1, -1);
	set_color(&textures->ceiling, -1, -1, -1);
	textures->hex_floor = 0;
	textures->hex_ceiling = 0;
	textures->counter = 0;
	textures->counter2 = 0;
}

static void	init_map(t_map *map)
{
	map->fd = 0;
	map->lines = 0;
	map->tab = NULL;
	map->file = NULL;
	map->height = 0;
	map->width = 0;
	map->end = 0;
}

void	init_world(t_world *world)
{
	world->mlx = NULL;
	world->texture_pixels = NULL;
	world->tex = NULL;
	init_window(&world->window);
	init_camera(&world->camera);
	init_textures(&world->textures);
	world->maptab = NULL;
	init_map(&world->map);
}
