/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:01:53 by crizapat          #+#    #+#             */
/*   Updated: 2025/01/24 12:39:02 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H 
# define MINITALK_H 

# include "utils/libft/libft.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

typedef struct	s_bits_buffer
{
	int bit;
	int byte;
}				t_bits_buffer;

#endif
