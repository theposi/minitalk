/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:26:58 by crizapat          #+#    #+#             */
/*   Updated: 2024/03/20 00:51:44 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int charac)
{
	if ((charac >= 'A' && charac <= 'Z')
		|| (charac >= 'a' && charac <= 'z'))
		return (1);
	return (0);
}
