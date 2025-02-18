/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:01:26 by crizapat          #+#    #+#             */
/*   Updated: 2025/02/01 01:48:47 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void signal_emitter(pid_t pid, char *message)
{
	int bit;
	int i;

	bit = 0;
	while (message[bit] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((unsigned char)message[bit] & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(200);
		}
		bit++;
	}
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
	}
}


int main(int argc, char **argv)
{
	client_banner();
	pid_t process_id;
	char *message;


	if (argc == 3)
	{
		process_id = ft_atoi(argv[1]);
		if (process_id <= 0)
		{
			ft_printf("[WRONG PID] -- try again\n");
			return 0;
		}
		message = argv[2];
		if (message[0] == 0)
		{
			ft_printf("[WRONG MESSAGE] -- try again\n");
			return 0;
		}
		signal_emitter(process_id, message);
	}
	else
		ft_printf("[INVALID ARGUMENTS] too few arguments, try again please");	
	return 0;
}
