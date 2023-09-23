/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:03 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:10 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	copy_vector(t_vect src, t_vect *dst)
{
	dst->x = src.x;
	dst->y = src.y;
}

void	add_vector(t_vect v1, t_vect v2, t_vect *result)
{
	t_vect	v1_copy;
	t_vect	v2_copy;

	copy_vector(v1, &v1_copy);
	copy_vector(v2, &v2_copy);
	result->x = v1_copy.x + v2_copy.x;
	result->y = v1_copy.y + v2_copy.y;
}

void	sub_vector(t_vect v1, t_vect v2, t_vect *result)
{
	t_vect	v1_copy;
	t_vect	v2_copy;

	copy_vector(v1, &v1_copy);
	copy_vector(v2, &v2_copy);
	result->x = v1_copy.x - v2_copy.x;
	result->y = v1_copy.y - v2_copy.y;
}

void	mult_vector(float m, t_vect vect, t_vect *result)
{
	result->x = vect.x * m;
	result->y = vect.y * m;
}
