/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:09 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
}

void	init_raycast(t_raycast *ray)
{
	ray->x = 0;
	set_vector(&ray->ray_direction, 0.0, 0.0);
	set_vector(&ray->camera_direction, 0.0, 0.0);
	set_vector(&ray->current_square, 0.0, 0.0);
	set_vector(&ray->side_dist, 0.0, 0.0);
	set_vector(&ray->delta_dist, 0.0, 0.0);
	set_vector(&ray->step, 0.0, 0.0);
	ray->wall_dist = 0.0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_stop = 0;
	init_data(&ray->img);
	ray->color = -1;
}
