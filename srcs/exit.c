/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_cub3d(void *param)
{
	t_world	*world;

	world = (t_world *)param;
	if (!world)
		exit(0);
	if (world->window.reference && world->mlx)
		mlx_destroy_window(world->mlx, world->window.reference);
	if (world->mlx)
	{
		mlx_destroy_display(world->mlx);
		mlx_loop_end(world->mlx);
		free(world->mlx);
	}
	free_world(world);
	exit(0);
	return (0);
}
