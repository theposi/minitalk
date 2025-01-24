/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:01:38 by crizapat          #+#    #+#             */
/*   Updated: 2025/01/24 13:21:06 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <signal.h>

t_bits_buffer g_server_buffer = {0, 0};

static void reset_data_buffers()
{
	g_server_buffer.bit = 0;
	g_server_buffer.byte = 0;
} 

static void signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_server_buffer.byte = (g_server_buffer.byte << 1) | 1;
	else if (signal == SIGUSR2) 
		g_server_buffer.byte = (g_server_buffer.byte << 1) | 0;
	g_server_buffer.bit++;

	//
    if (g_server_buffer.bit == 8) {
        printf("%c", g_server_buffer.byte);
        fflush(stdout); // Asegurar que se imprima inmediatamente
        reset_data_buffers();
    }
	//
}

int main ()
{
	int server_pid = getpid();
	printf("[SERVER PID] --> [%d]\n", server_pid);

	struct sigaction sign;
	sign.sa_handler = signal_handler;

	while(1)
	{
		sleep(1);
	}
	return 0;
}
