/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:01 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda_init(t_raycast *r, t_world *w)
{
	if (r->ray_direction.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (w->camera.position.x - r->current_square.x
				) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->current_square.x + 1.0 - w->camera.position.x
				) * r->delta_dist.x;
	}
	if (r->ray_direction.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (w->camera.position.y - r->current_square.y
				) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->current_square.y + 1.0 - w->camera.position.y
				) * r->delta_dist.y;
	}
}

void	dda_step(t_raycast *r, t_world *w)
{
	if (r->side_dist.x < r->side_dist.y)
	{
		r->side_dist.x += r->delta_dist.x;
		r->current_square.x += r->step.x;
		r->side = 0;
	}
	else
	{
		r->side_dist.y += r->delta_dist.y;
		r->current_square.y += r->step.y;
		r->side = 1;
	}
	if (get_square(r->current_square, w) > '0')
	{
		r->hit = 1;
	}
}
