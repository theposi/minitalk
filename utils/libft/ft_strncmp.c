/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:55:59 by crizapat          #+#    #+#             */
/*   Updated: 2024/03/20 00:37:45 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	while ((i < len) && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (((unsigned char) str1[i] - (unsigned char) str2[i]));
		i++;
	}
	return (0);
}
