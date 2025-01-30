/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:52:30 by crizapat          #+#    #+#             */
/*   Updated: 2024/09/06 11:31:31 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_putnumb(int numb, int *index)
{
	unsigned int	number;
	char			sign;

	if (numb >= 0)
	{
		number = numb;
	}
	else
	{
		sign = '-';
		number = -numb;
		ft_putchar(sign, index);
	}
	if (number >= 10)
	{
		ft_putnumb(numb / 10, index);
		ft_putchar(numb % 10 + '0', index);
	}
	else
	{
		ft_putchar((number + '0'), index);
	}
	return ;
}

void	ft_putstr(char *str, int *index)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		(*index)++;
		i++;
	}
	return ;
}

void	ft_puthex(unsigned long n, char format, int *index)
{
	int				i;
	char			*base;
	unsigned int	base_length;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	base_length = 16;
	if (n > (base_length -1))
	{
		ft_puthex(n / base_length, format, index);
		i++;
	}
	ft_putchar(*(base + (n % base_length)), index);
	i++;
	return ;
}

void	ft_unsigned_numb(unsigned int n, int *index)
{
	if (n >= 10)
		ft_unsigned_numb(n / 10, index);
	ft_putchar(((n % 10) + '0'), index);
	return ;
}

void	ft_pointer_dir(void *ptr, char format, int *index)
{
	if (!ptr)
	{
		ft_putstr("(nil)", index);
		return ;
	}
	ft_putstr("0x", index);
	ft_puthex((unsigned long) ptr, format, index);
	return ;
}
