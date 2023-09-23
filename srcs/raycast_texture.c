/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:03 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:10 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	pixel;

	pixel = y * (data->line_length / 4) + x;
	data->addr[pixel] = color;
}

void	init_tex(t_world *world, t_raycast *ray, t_textures *tex)
{
	get_texture_index(world, ray);
	tex->x = (int)(ray->wall_x * world->textures.texil);
	if ((ray->side == 0 && ray->ray_direction.x < 0)
		|| (ray->side == 1 && ray->ray_direction.y > 0))
		tex->x = world->textures.texil - tex->x - 1;
	tex->step = 1.0 * world->textures.texil / ray->line_height;
	tex->pos = (ray->draw_start - SCREEN_HEIGHT / 2
			+ ray->line_height / 2) * tex->step;
}

static void	draw_floor(t_raycast *ray, t_textures *tex)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		my_mlx_pixel_put(&ray->img, ray->x, y, create_trgb(0,
				tex->ceiling.r, tex->ceiling.g, tex->ceiling.b));
		y++;
	}
}

static void	draw_ceiling(t_raycast *ray, t_textures *tex)
{
	int	y;

	y = ray->draw_stop;
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(&ray->img, ray->x, y, create_trgb(0, tex->floor.r,
				tex->floor.g, tex->floor.b));
		y++;
	}
}

void	draw_vertical_line(t_world *world, t_raycast *ray)
{
	int			y;
	int			color;
	t_textures	*tex;

	tex = &world->textures;
	init_tex(world, ray, tex);
	draw_floor(ray, tex);
	y = ray->draw_start;
	while (y < ray->draw_stop)
	{
		tex->y = (int)tex->pos & (world->textures.texil - 1);
		tex->pos += tex->step;
		color = world->tex[tex->index][world->textures.texil * tex->y + tex->x];
		if (tex->index == 0 || tex->index == 2)
			color = (color >> 1) & 8355711;
		if (color > 0)
			world->texture_pixels[y][ray->x] = color;
		my_mlx_pixel_put(&ray->img, ray->x, y, world->texture_pixels[y][ray->x]
			);
		y++;
	}
	draw_ceiling(ray, tex);
}
