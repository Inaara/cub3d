/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:01 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	no_digit(char *str)
{
	int		i;
	bool	flag;

	i = 0;
	flag = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			flag = false;
		i++;
	}
	return (flag);
}

static t_color	rgb_array(char **convert, t_color rgb)
{
	rgb.r = ft_atoi(convert[0]);
	rgb.g = ft_atoi(convert[1]);
	rgb.b = ft_atoi(convert[2]);
	if (rgb.r == -1 || rgb.g == -1 || rgb.b == -1 || no_digit(convert[0]) == 1
		|| no_digit(convert[1]) == true || no_digit(convert[2]) == true)
	{
		print_error("Missing or invalid color");
		rgb.r = -1;
		rgb.g = -1;
		rgb.b = -1;
		free_maptab((void **)convert);
		return (rgb);
	}
	free_maptab((void **)convert);
	return (rgb);
}

static t_color	set_colors(char *s)
{
	char	**convert;
	t_color	rgb;
	int		count;

	convert = ft_split(s, ',');
	count = 0;
	while (convert[count])
		count++;
	rgb.r = -1;
	rgb.g = -1;
	rgb.b = -1;
	if (count != 3)
	{
		free_maptab((void **)convert);
		return (rgb);
	}
	return (rgb_array(convert, rgb));
}

int	colors(t_world *world, t_textures *tex, char *s, int i)
{
	(void)world;
	if (s[i + 1] && ft_isprint(s[i + 1]))
		return (print_error("invalid color"));
	if (tex->ceiling.r == -1 && tex->ceiling.g == -1
		&& tex->ceiling.b == -1 && s[i] == 'C')
	{
		tex->counter2++;
		tex->ceiling = set_colors(s + i + 1);
		if (tex->ceiling.r == -1 || tex->ceiling.g == -1
			|| tex->ceiling.b == -1)
			return (print_error("Invalid ceiling color"));
	}
	else if (tex->floor.r == -1 && tex->floor.g == -1
		&& tex->floor.b == -1 && s[i] == 'F')
	{
		tex->counter2++;
		tex->floor = set_colors(s + i + 1);
		if (tex->floor.r == -1 || tex->floor.g == -1
			|| tex->floor.b == -1)
			return (print_error("Invalid floor color"));
	}
	else
		return (print_error("Missing or extra floor or ceiling color"));
	return (0);
}	

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
