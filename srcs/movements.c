/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:09 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <X11/keysym.h>

#define KEY_A 97
#define KEY_D 100
#define KEY_W 119
#define KEY_S 115

void	turn_camera(int left, t_world *world, float rs)
{
	float		old_dir_x;
	float		old_plane_x;
	t_camera	*c;

	c = &world->camera;
	old_dir_x = world->camera.direction.x;
	old_plane_x = world->camera.plane.x;
	if (world->camera.dir != 'W' && world->camera.dir != 'E')
		left = 1 - left;
	if (left)
	{
		c->direction.x = c->direction.x * cosf(rs) - c->direction.y * sinf(rs);
		c->direction.y = old_dir_x * sinf(rs) + c->direction.y * cosf(rs);
		c->plane.x = old_plane_x * cosf(rs) - c->plane.y * sinf(rs);
		c->plane.y = old_plane_x * sinf(rs) + c->plane.y * cosf(rs);
	}
	else
	{
		c->direction.x = old_dir_x * cosf(-rs) - c->direction.y * sinf(-rs);
		c->direction.y = old_dir_x * sinf(-rs) + c->direction.y * cosf(-rs);
		c->plane.x = old_plane_x * cosf(-rs) - c->plane.y * sinf(-rs);
		c->plane.y = old_plane_x * sinf(-rs) + c->plane.y * cosf(-rs);
	}
}

int	is_wall(t_world *world, t_vect position)
{
	if (get_square(position, world) > '0')
		return (1);
	return (0);
}

void	move_camera(int up, int side, t_world *world)
{
	float	speed;
	t_vect	direction;
	t_vect	new_position;

	speed = 0.3;
	if (side)
	{
		get_perpandicular(world->camera.direction, &direction);
		if (world->camera.dir != 'W' && world->camera.dir != 'E')
			up = 1 - up;
	}
	else
		copy_vector(world->camera.direction, &direction);
	mult_vector(speed, direction, &direction);
	if (up)
		add_vector(world->camera.position, direction, &new_position);
	else
		sub_vector(world->camera.position, direction, &new_position);
	if (!is_wall(world, new_position))
		copy_vector(new_position, &world->camera.position);
}

int	monitor_input(int key, t_world *world)
{
	if (key == KEY_W)
		move_camera(1, 0, world);
	else if (key == KEY_S)
		move_camera(0, 0, world);
	else if (key == KEY_A)
		move_camera(0, 1, world);
	else if (key == KEY_D)
		move_camera(1, 1, world);
	else if (key == XK_Left)
		turn_camera(1, world, 0.1);
	else if (key == XK_Right)
		turn_camera(0, world, 0.1);
	else if (key == XK_Escape)
		exit_cub3d(world);
	return (0);
}
