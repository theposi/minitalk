/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:01:38 by crizapat          #+#    #+#             */
/*   Updated: 2025/01/30 16:49:45 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_bits_buffer g_server_buffer = {0, 0};

static void reset_data_buffers()
{
	g_server_buffer.bit = 0;
	g_server_buffer.byte = 0;
} 

static void signal_handler(int signal)
{
	char *message;

	if (signal == SIGUSR1) {
		g_server_buffer.bit = (g_server_buffer.bit << 1) | 1;	
	}
	if (signal == SIGUSR2) {
		g_server_buffer.bit = (g_server_buffer.bit << 1) | 0;	
	}
	g_server_buffer.byte++;
}

int main ()
{
	int server_pid = getpid();
	ft_printf("[SERVER PID] --> [%d]\n", server_pid);

	struct sigaction sa;

	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while(1)
	{
		pause();
	}
	return 0;
}
