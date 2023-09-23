/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:09 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_square(t_vect position, t_world *world)
{
	return (world->maptab[(int )position.y][(int)position.x]);
}
