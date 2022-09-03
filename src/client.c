/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:45:20 by zarslan           #+#    #+#             */
/*   Updated: 2022/06/05 13:56:57 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isdigit(argv[1]))
	{
		ft_printf("Eksik veya hatalı argüman girdiniz...");
		return (0);
	}
	ft_post(ft_atoi(argv[1]), argv[2]);
}
