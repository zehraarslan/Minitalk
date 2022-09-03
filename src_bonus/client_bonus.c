/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:48:03 by zarslan           #+#    #+#             */
/*   Updated: 2022/06/05 13:50:40 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_kill(int pid, char character)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((character & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(50);
	}
}

void	ft_post(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_kill(pid, str[i]);
		i++;
	}
	ft_kill(pid, '\n');
}

void	c_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)siginfo;
	(void)context;
	ft_printf("Başarılı...");
}

int	main(int argc, char **argv)
{
	struct sigaction	c_act;

	if (argc != 3 || !ft_isdigit(argv[1]))
	{
		ft_printf("Eksik veya hatalı argüman girdiniz...");
		return (0);
	}
	c_act.sa_sigaction = c_handler;
	c_act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &c_act, NULL);
	ft_post(ft_atoi(argv[1]), argv[2]);
}
