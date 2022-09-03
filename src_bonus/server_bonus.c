/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:48:07 by zarslan           #+#    #+#             */
/*   Updated: 2022/06/05 12:58:41 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int signo, siginfo_t *siginfo, void *context)
{
	static int	bit = 7;
	static int	character = 0;

	(void)context;
	if (signo == SIGUSR1)
		character |= (1 << bit);
	else if (signo == SIGUSR2)
		character |= (0 << bit);
	bit--;
	if (bit < 0)
	{
		ft_printf("%c", character);
		if (character == '\n')
			kill(siginfo->si_pid, SIGUSR1);
		character = 0;
		bit = 7;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("PID :  %u\n", getpid());
	act.sa_sigaction = ft_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
}
