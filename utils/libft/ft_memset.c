/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:20:15 by crizapat          #+#    #+#             */
/*   Updated: 2024/03/20 00:53:10 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int charac, size_t len)
{
	unsigned char	*str;
	unsigned char	value;

	str = ptr;
	value = (unsigned char)charac;
	while (len > 0)
	{
		*str++ = value;
		len--;
	}
	return (ptr);
}
