/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:03 by mkaploun          #+#    #+#             */
/*   Updated: 2023/02/24 14:51:10 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	words_count(char *s, char *c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	(void)c;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i] == '\n')
			return (cnt);
		cnt++;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
	}
	return (cnt);
}	
