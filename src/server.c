/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:01:38 by crizapat          #+#    #+#             */
/*   Updated: 2025/02/14 17:47:26 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_bits_buffer	g_server_buffer = {0, 0, NULL};

static void	reset_data_buffers(void)
{
	g_server_buffer.bit = 0;
	g_server_buffer.byte = 0;
}

static char	*append_char(char *str, char c)
{
	int		len;
	char	*new_str;

	len = 0;
	if (str)
		len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	if (str)
	{
		ft_memcpy(new_str, str, len);
		free(str);
	}
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (new_str);
}

static void	process_byte(void)
{
	char	*temp;

	if (g_server_buffer.byte == '\0')
	{
		if (g_server_buffer.msg)
		{
			ft_printf("%s\n", g_server_buffer.msg);
			free(g_server_buffer.msg);
			g_server_buffer.msg = NULL;
		}
	}
	else
	{
		temp = append_char(g_server_buffer.msg, g_server_buffer.byte);
		if (!temp)
		{
			ft_printf("Error: Memory allocation failed.\n");
			exit(1);
		}
		g_server_buffer.msg = temp;
	}
	reset_data_buffers();
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_server_buffer.byte = (g_server_buffer.byte << 1) | 1;
	else if (signal == SIGUSR2)
		g_server_buffer.byte = (g_server_buffer.byte << 1) | 0;
	g_server_buffer.bit++;
	if (g_server_buffer.bit == 8)
		process_byte();
}

int	main(void)
{
	int					server_pid;
	struct sigaction	sign;

	server_banner();
	server_pid = getpid();
	ft_printf("[SERVER PID] --> [%d]\n", server_pid);
	sign.sa_handler = &signal_handler;
	sign.sa_flags = SA_RESTART;
	sigemptyset(&sign.sa_mask);
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
	while (1)
		pause ();
	return (0);
}
