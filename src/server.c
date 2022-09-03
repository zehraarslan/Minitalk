/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:45:18 by zarslan           #+#    #+#             */
/*   Updated: 2022/06/05 12:59:25 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signo, siginfo_t *siginfo, void *context)
{
	static int	bit = 7;
	static int	character = 0;

	(void)context;
	(void)siginfo;
	if (signo == SIGUSR1)
		character |= (1 << bit);
	else if (signo == SIGUSR2)
		character |= (0 << bit);
	bit--;
	if (bit < 0)
	{
		ft_printf("%c", character);
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
