/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:52:47 by zarslan           #+#    #+#             */
/*   Updated: 2022/02/27 02:11:48 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len = *len + 1;
}

void	ft_putstr(char *s, int *len)
{
	if (!s)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*s)
	{
		write(1, s++, 1);
		*len = *len +1;
	}
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-', len);
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, len);
	ft_putchar(nbr % 10 + '0', len);
}

void	ft_puthex(size_t n, char *digit, int *len)
{
	if (n == 0)
		ft_putchar('0', len);
	if (n < 0)
	{
		n = -n;
	}
	if (n > 0)
	{
		if (n >= 16)
			ft_puthex(n / 16, digit, len);
		ft_putchar(digit[n % 16], len);
	}
}

void	ft_putuns(size_t n, char *digit, int *len)
{
	if (n == 0)
		ft_putchar('0', len);
	if (n < 0)
	{
		n = -n;
	}
	if (n > 0)
	{
		if (n >= 10)
			ft_putuns(n / 10, digit, len);
		ft_putchar(digit[n % 10], len);
	}
}
