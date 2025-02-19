/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 01:33:06 by crizapat          #+#    #+#             */
/*   Updated: 2025/02/04 16:44:09 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

#define MAGENTA	"\x1b[35m"
#define CIAN "\x1b[36m"
#define RESET	"\x1b[0m"

void client_banner(void)
{
    printf(MAGENTA" ██████╗██╗     ██╗███████╗███╗   ██╗████████╗\n"RESET);
    printf(MAGENTA"██╔════╝██║     ██║██╔════╝████╗  ██║╚══██╔══╝\n"RESET);
    printf(MAGENTA"██║     ██║     ██║█████╗  ██╔██╗ ██║   ██║   \n"RESET);
    printf(MAGENTA"██║     ██║     ██║██╔══╝  ██║╚██╗██║   ██║   \n"RESET);
    printf(MAGENTA"╚██████╗███████╗██║███████╗██║ ╚████║   ██║   \n"RESET);
    printf(MAGENTA" ╚═════╝╚══════╝╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n"RESET);
	printf("PRINTER AREA________________________________________\n");
}

void server_banner(void)
{
	printf(CIAN"███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n"RESET); 
	printf(CIAN"██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n"RESET);
	printf(CIAN"███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n"RESET);
	printf(CIAN"╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n"RESET);
	printf(CIAN"███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n"RESET);
	printf(CIAN"╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n"RESET);
	printf("RECEIVING AREA________________________________________\n");
}
