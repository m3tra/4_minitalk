/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:27:13 by fporto            #+#    #+#             */
/*   Updated: 2021/09/07 19:27:14 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*print_string(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	free(str);
	return (NULL);
}

void	reply(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	sighandler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bit = 0;
	static int	pid = 0;
	static char	*str = 0;

	(void)context;
	if ((info)->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bit;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bit;
	if (++bit == 8)
	{
		if (!c)
		{
			str = print_string(str);
			reply(pid, SIGUSR1);
		}
		else
			str = ft_strcat_char(str, c);
		bit = 0;
		c = 0xFF;
	}
	reply(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig_s;
	sigset_t			mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);
	sig_s.sa_flags = SA_SIGINFO;
	sig_s.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &sig_s, NULL);
	sigaction(SIGUSR2, &sig_s, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
