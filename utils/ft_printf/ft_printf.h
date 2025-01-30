/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:52:41 by crizapat          #+#    #+#             */
/*   Updated: 2024/09/06 11:28:04 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char charac, int *index);
void	ft_putnumb(int numb, int *index);
void	ft_putstr(char *str, int *index);
void	ft_puthex(unsigned long n, char format, int *index);
void	ft_unsigned_numb(unsigned int n, int *index);
void	ft_pointer_dir(void *ptr, char format, int *index);
void	format_catcher(char format, va_list args, int *index);
int		ft_printf(char const *format, ...);

#endif
