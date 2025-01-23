/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:04:15 by crizapat          #+#    #+#             */
/*   Updated: 2024/04/17 11:06:53 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*ptr;

	if (items && size && items > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(items * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, items * size);
	return (ptr);
}
