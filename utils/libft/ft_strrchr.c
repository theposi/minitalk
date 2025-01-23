/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:21:36 by crizapat          #+#    #+#             */
/*   Updated: 2024/01/30 10:54:43 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int charac)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if ((unsigned char)str[i] == (unsigned char)charac)
			return ((char *)&str[i]);
		if (charac == 0 && str[i] == '\0')
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
