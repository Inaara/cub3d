/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:09 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	raycast(t_world *world)
{
	t_raycast	r;

	init_raycast(&r);
	init_texture_pixels(world);
	raycasting_init(&r, world);
	while (r.x < SCREEN_WIDTH)
	{
		raycasting_step_init(&r, world);
		dda_init(&r, world);
		while (!r.hit)
			dda_step(&r, world);
		wall_dist(&r);
		get_line(&r, &world->camera);
		draw_vertical_line(world, &r);
		r.x++;
	}
	mlx_put_image_to_window(world->mlx, world->window.reference,
		r.img.img, 0, 0);
	mlx_destroy_image(world->mlx, r.img.img);
	return (0);
}

static int	check_input(t_world *world, char **av)
{
	if (check_input_file(av[1]) == -1)
		return (print_error("No such file"));
	parse_world(av[1], world);
	if (get_info(world, world->map.tab) == -1)
		return (free_world(world));
	if (check_map(world, world->maptab) == -1)
		return (free_world(world));
	if (check_textures(world, &world->textures) == -1)
		return (free_world(world));
	return (0);
}

int	main(int ac, char **av)
{
	t_world	world;

	if (ac != 2)
		return (print_error("Wrong number of arguments"));
	init_world(&world);
	world.textures.texil = -1;
	if (check_input(&world, av) != 0)
		return (1);
	world.mlx = mlx_init();
	if (!world.mlx)
		return (print_error("Couldn't init the World structure"));
	world.window.reference = mlx_new_window(world.mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cub3D");
	mlx_hook(world.window.reference, 17, 0, &exit_cub3d, &world);
	if (!world.window.reference)
		return (print_error("Couldn't init the Window"));
	set_textures(&world);
	mlx_loop_hook(world.mlx, &raycast, (void *)&world);
	mlx_key_hook(world.window.reference, &monitor_input, &world);
	mlx_loop(world.mlx);
}
