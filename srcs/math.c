/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:02 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:09 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	get_max_len(t_map *map, int i)
{
	size_t	biggest_len;

	biggest_len = ft_strlen(map->tab[i]);
	while (map->tab[i])
	{
		if (ft_strlen(map->tab[i]) > biggest_len)
			biggest_len = ft_strlen(map->tab[i]);
		i++;
	}
	return (biggest_len);
}

float	absolute_value(float value)
{
	if (value >= 0)
		return (value);
	return (-value);
}
