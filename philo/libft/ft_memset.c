/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:50:09 by ihama             #+#    #+#             */
/*   Updated: 2023/03/26 04:44:51 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pointeur;
	size_t			i;

	i = 0;
	pointeur = (unsigned char *)b;
	while (i < len)
	{
		*pointeur = (unsigned char)c;
		i++;
		pointeur++;
	}
	return (b);
}
