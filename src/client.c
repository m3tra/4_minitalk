/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:27:11 by fporto            #+#    #+#             */
/*   Updated: 2021/09/08 13:54:38 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signum)
{
	static int	flag = 1;

	if (signum == SIGUSR2)
	{
		if (flag)
		{
			ft_putstr_fd("Sending message: ", 1);
			flag = 0;
		}
		else
			ft_putchar_fd('.', 1);
	}
	if (signum == SIGUSR1)
	{
		ft_putstr_fd("\nMessage recieved.\n", 1);
		flag = 1;
		exit(EXIT_SUCCESS);
	}
}

void	send_bits(int pid, char *str)
{
	int	i;
	int	bit;

	bit = -1;
	i = 0;
	if (!str)
		exit(EXIT_FAILURE);
	while (1)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (str[i] & (0x80 >> bit))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			}
			else if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
			usleep(100);
		}
		if (!str[i])
			break ;
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3 || !ft_isstrdigit(argv[1]))
	{
		ft_putstr_fd("Usage: ./client [PID] [STR]\n", 1);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	pid = ft_atoi(argv[1]);
	send_bits(pid, argv[2]);
}
