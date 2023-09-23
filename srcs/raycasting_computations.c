/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_computations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:03 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:10 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	get_dist_side(float ray_direction)
{
	if (ray_direction == 0)
		return (1e30);
	return (absolute_value((1 / ray_direction)));
}

void	raycasting_init(t_raycast *r, t_world *world)
{
	r->img.img = mlx_new_image(world->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	r->img.addr = (int *)mlx_get_data_addr(r->img.img,
			&r->img.bits_per_pixel, &r->img.line_length, &r->img.endian);
	r->x = 0;
}

void	raycasting_step_init(t_raycast *r, t_world *w)
{
	r->wall_dist = 0;
	r->hit = 0;
	r->side = 0;
	set_vector(&r->side_dist, 0, 0);
	set_vector(&r->step, 0, 0);
	set_vector(&r->camera_direction, 2 * r->x / (float)SCREEN_WIDTH - 1, 0);
	set_vector(&r->ray_direction,
		w->camera.direction.x + w->camera.plane.x * r->camera_direction.x,
		w->camera.direction.y + w->camera.plane.y * r->camera_direction.x);
	set_vector(&r->current_square, (int)w->camera.position.x,
		(int)w->camera.position.y);
	set_vector(&r->delta_dist, get_dist_side(r->ray_direction.x),
		get_dist_side(r->ray_direction.y));
}

void	wall_dist(t_raycast *r)
{
	if (r->side == 0)
	{
		r->wall_dist = (r->side_dist.x - r->delta_dist.x);
	}
	else
	{
		r->wall_dist = (r->side_dist.y - r->delta_dist.y);
	}
}

void	get_line(t_raycast *r, t_camera *camera)
{
	r->line_height = SCREEN_HEIGHT / r->wall_dist;
	r->draw_start = -r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_stop = r->line_height / 2 + SCREEN_HEIGHT / 2;
	if (r->draw_stop >= SCREEN_HEIGHT)
		r->draw_stop = SCREEN_HEIGHT - 1;
	if (r->side == 0)
		r->wall_x = camera->position.y + r->wall_dist * r->ray_direction.y;
	else
		r->wall_x = camera->position.x + r->wall_dist * r->ray_direction.x;
	r->wall_x -= floor(r->wall_x);
}
