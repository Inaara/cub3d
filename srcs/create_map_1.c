/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:01 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	space_to_wall(t_world *world)
{
	int	i;
	int	j;

	i = 0;
	while (world->maptab[i])
	{
		j = 0;
		while (world->maptab[i][++j])
		{
			if ((world->maptab[i][j] == ' ' || world->maptab[i][j] == '\t'
						|| world->maptab[i][j] == '\r'
						|| world->maptab[i][j] == '\v'
						|| world->maptab[i][j] == '\f')
				&& j != world->maptab[i][ft_strlen(world->maptab[i]) - 1])
				world->maptab[i][j] = '1';
		}
		i++;
	}
}
