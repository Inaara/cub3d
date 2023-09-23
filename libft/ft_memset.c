/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazimzha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:21:08 by iazimzha          #+#    #+#             */
/*   Updated: 2021/12/08 11:47:56 by iazimzha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;

	n = 0;
	while (n < len)
	{
		((unsigned char *)b)[n] = c;
		n++;
	}
	return (b);
}