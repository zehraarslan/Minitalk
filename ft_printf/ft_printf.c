/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:42:25 by zarslan           #+#    #+#             */
/*   Updated: 2022/02/27 02:10:46 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(char c, va_list list_arg, int *x)
{
	if (c == 'c')
		ft_putchar(va_arg(list_arg, int), x);
	else if (c == 's')
		ft_putstr(va_arg(list_arg, char *), x);
	else if (c == 'p')
	{
		ft_putstr("0x", x);
		ft_puthex(va_arg(list_arg, size_t), "0123456789abcdef", x);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list_arg, int), x);
	else if (c == 'x')
		ft_puthex(va_arg(list_arg, unsigned int), "0123456789abcdef", x);
	else if (c == 'X')
		ft_puthex(va_arg(list_arg, unsigned int), "0123456789ABCDEF", x);
	else if (c == 'u')
		ft_putuns(va_arg(list_arg, unsigned int), "0123456789", x);
	else if (c == '%')
		ft_putchar('%', x);
}

int	ft_printf(const char *str, ...)
{
	va_list	list_arg;
	int		len;

	len = 0;
	va_start(list_arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_type(*str, list_arg, &len);
		}
		else
		{
			len += write(1, str, 1);
		}
		str++;
	}
	va_end(list_arg);
	return (len);
}
