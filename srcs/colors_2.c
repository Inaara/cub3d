/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:01 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_wall_color(char type_wall)
{
	if (type_wall == '1')
		return (create_trgb(0, 255, 0, 0));
	return (create_trgb(0, 255, 255, 0));
}

int	get_darker(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16 & 0xFF) / 2;
	g = (color >> 8 & 0xFF) / 2;
	b = (color & 0xFF) / 2;
	return (create_trgb(0, r, g, b));
}

void	choose_color(t_raycast *r, t_world *world)
{
	r->color = get_wall_color(get_square(r->current_square, world));
	if (r->side == 1)
	{
		r->color = get_darker(r->color);
	}
}

char	get_color_name(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16 & 0xFF);
	g = (color >> 8 & 0xFF);
	b = (color & 0xFF);
	if (r == 255 && g == 0 && b == 0)
		return ('R');
	if (r > 0 && g == 0 && b == 0)
		return ('r');
	if (r == 0 && g == 255 && b == 0)
		return ('G');
	if (r == 0 && g > 0 && b == 0)
		return ('g');
	if (r == 0 && g == 0 && b == 255)
		return ('B');
	if (r == 0 && g == 0 && b > 0)
		return ('b');
	if (r == 255 && g == 255 && b == 255)
		return ('W');
	if (r > 0 && g > 0 && b > 0)
		return ('w');
	return ('y');
}
