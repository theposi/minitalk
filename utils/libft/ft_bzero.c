/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:54:02 by crizapat          #+#    #+#             */
/*   Updated: 2024/03/20 00:51:14 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = ptr;
	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}
