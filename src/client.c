/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:01:26 by crizapat          #+#    #+#             */
/*   Updated: 2025/01/23 12:38:16 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <stdio.h>

void printBinary(int pid, char *message)
{
	int i, letter;

	letter = 0;
	while (message[letter] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((unsigned char)message[letter] & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(90);
		}
		letter++;
	}
}

int main(int argc, char **argv)
{
	int process_id;
	char *message;

	if (argc == 3)
	{
		process_id = ft_atoi(argv[1]);
		if (process_id < 0)
		{
			printf("[WRONG PID] -- try again\n");
			return 0;
		}
		message = argv[2];
		if (message[0] == 0)
		{
			printf("[WRONG	MESSAGE] -- try again\n");
			return 0;
		}
		printBinary(process_id, message);
	}
	else
	{
		printf("[INVALID ARGUMENTS] too few arguments, try again please");	
	}
	return 0;
}
