/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format-specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:52:24 by crizapat          #+#    #+#             */
/*   Updated: 2024/09/06 11:41:14 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_putchar(char charac, int *index)
{
	if (write(1, &charac, 1) == -1)
		return (-1);
	(*index)++;
	return (0);
}

void	format_catcher(char format, va_list args, int *index)
{
	if (format == 'c')
		ft_putchar((char)va_arg(args, int), index);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), index);
	else if (format == 'i' || format == 'd')
		ft_putnumb(va_arg(args, int), index);
	else if (format == 'x' || format == 'X')
		ft_puthex(va_arg(args, unsigned int), format, index);
	else if (format == 'p')
		ft_pointer_dir(va_arg(args, void *), format, index);
	else if (format == 'u')
		ft_unsigned_numb(va_arg(args, unsigned int), index);
	else if (format == '%')
		ft_putchar('%', index);
	return ;
}
