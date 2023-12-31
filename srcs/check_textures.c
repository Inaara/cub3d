/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:01 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_texture_file(char *file)
{
	int	fd;
	int	len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	len = ft_strlen(file);
	if ((file[len - 3] != 'x' || file[len - 2] != 'p'
			|| file[len - 1] != 'm' || file[len - 4] != '.'))
		return (-1);
	return (0);
}

static int	check_color(t_color *color)
{
	if (color->r < 0 || color->r > 255)
		return (print_error("Invalid color"));
	if (color->g < 0 || color->g > 255)
		return (print_error("Invalid color"));
	if (color->b < 0 || color->b > 255)
		return (print_error("Invalid color"));
	return (0);
}

static unsigned long	convert_color_to_hex(t_color *color)
{
	unsigned long	hex;
	int				r;
	int				g;
	int				b;

	r = color->r;
	g = color->g;
	b = color->b;
	hex = ((r & 0xff) << 16) + ((g & 0Xff) << 8) + (b & 0xff);
	return (hex);
}

int	check_textures(t_world *world, t_textures *textures)
{
	(void)world;
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (print_error("Wrong texture"));
	if (check_texture_file(textures->north) == -1
		|| check_texture_file(textures->south) == -1
		|| check_texture_file(textures->west) == -1
		|| check_texture_file(textures->east) == -1)
		return (print_error("Invalid texture file/s"));
	if (check_color(&textures->floor) == -1
		|| check_color(&textures->ceiling) == -1)
		return (-1);
	textures->hex_floor = convert_color_to_hex(&textures->floor);
	textures->hex_ceiling = convert_color_to_hex(&textures->ceiling);
	return (0);
}
