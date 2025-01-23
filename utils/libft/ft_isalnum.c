/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:09:26 by crizapat          #+#    #+#             */
/*   Updated: 2024/03/20 00:51:35 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	if ((alnum >= 'A' && alnum <= 'Z')
		|| (alnum >= 'a' && alnum <= 'z')
		|| (alnum >= '0' && alnum <= '9'))
		return (1);
	return (0);
}
