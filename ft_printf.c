/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:59:07 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/10 19:18:36 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(char c, va_list args, int *ret)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), ret);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), ret);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), ret);
	else if (c == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), ret);
	else if (c == 'x')
		ft_put_hexa(va_arg(args, unsigned int), ret, 'l');
	else if (c == 'X')
		ft_put_hexa(va_arg(args, unsigned int), ret, 'u');
	else if (c == 'p')
	{
		ft_putstr("0x", ret);
		ft_putadd(va_arg(args, unsigned long), ret);
	}
	else if (c == '%')
		ft_putchar('%', ret);
	else
		ft_putchar(c, ret);
}

int	ft_printf(const char *fmt, ...)
{
	int		ret;
	int		i;
	va_list	args;

	i = 0;
	ret = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (!fmt[i + 1])
				return (ret);
			print_args(fmt[i + 1], args, &ret);
			i++;
		}
		else
			ft_putchar(fmt[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
