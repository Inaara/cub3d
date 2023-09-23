/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:03 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:10 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	set_vector(t_vect *vect, float x, float y)
{
	vect->x = x;
	vect->y = y;
}

void	get_perpandicular(t_vect src, t_vect *result)
{
	t_vect	copy;

	copy_vector(src, &copy);
	result->x = copy.y;
	result->y = -copy.x;
}
