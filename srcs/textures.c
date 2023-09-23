/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:03 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:53:04 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_img_for_texture(t_world *w, t_data *img, char *path)
{
	int	dimension;
	int	last_dimension;

	dimension = 0;
	last_dimension = w->textures.texil;
	init_data(img);
	img->img = mlx_xpm_file_to_image(w->mlx, path, &w->textures.texil,
			&dimension);
	if (img->img == NULL)
	{
		print_error("Couldn't convert xpm file to image");
		exit_cub3d(w);
	}
	if (dimension != w->textures.texil
		|| (last_dimension != -1 && last_dimension != w->textures.texil))
	{
		print_error("Texture dimension issue");
		mlx_destroy_image(w->mlx, img->img);
		exit_cub3d(w);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return ;
}

static int	*unwrap_texture(t_world *world, char *path)
{
	t_data	img;
	int		*arr;
	int		i;
	int		j;

	init_img_for_texture(world, &img, path);
	arr = ft_calloc(1,
			sizeof * arr * world->textures.texil * world->textures.texil);
	if (!arr)
	{
		print_error("Couldn't unwrap the texture");
		exit_cub3d(world);
	}
	i = -1;
	while (++i < world->textures.texil)
	{
		j = -1;
		while (++j < world->textures.texil)
			arr[i * world->textures.texil + j] = img.addr[
				i * world->textures.texil + j];
	}
	mlx_destroy_image(world->mlx, img.img);
	return (arr);
}

void	set_textures(t_world *world)
{
	world->tex = ft_calloc(5, sizeof * world->tex);
	if (!world->tex)
	{
		print_error("Couldn't allocate the texture array");
		exit_cub3d(world);
	}
	world->tex[0] = unwrap_texture(world, world->textures.north);
	world->tex[1] = unwrap_texture(world, world->textures.south);
	world->tex[2] = unwrap_texture(world, world->textures.east);
	world->tex[3] = unwrap_texture(world, world->textures.west);
}

void	init_texture_pixels(t_world *world)
{
	int	i;

	if (world->texture_pixels)
		free_maptab((void **)world->texture_pixels);
	world->texture_pixels = ft_calloc(SCREEN_HEIGHT + 1,
			sizeof * world->texture_pixels);
	if (!world->texture_pixels)
		exit_cub3d(world);
	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		world->texture_pixels[i] = ft_calloc(SCREEN_WIDTH + 1,
				sizeof * world->texture_pixels);
		if (!world->texture_pixels[i])
			exit_cub3d(world);
		i++;
	}
}

void	get_texture_index(t_world *world, t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_direction.x < 0)
			world->textures.index = 3;
		else
			world->textures.index = 2;
	}
	else
	{
		if (ray->ray_direction.y > 0)
			world->textures.index = 1;
		else
			world->textures.index = 0;
	}
}
