/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazimzha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:59:02 by iazimzha          #+#    #+#             */
/*   Updated: 2021/12/08 11:49:14 by iazimzha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 != NULL && s2 != NULL && (str != 0))
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (0);
}
