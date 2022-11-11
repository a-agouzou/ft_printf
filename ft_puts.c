/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:00:36 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/09 10:01:08 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ret)
{
	write(1, &c, 1);
	*ret = *ret + 1;
}

void	ft_putstr(char *s, int *ret)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], ret);
		i++;
	}
}

void	ft_putnbr(int n, int *ret)
{
	if (n == -2147483648)
	{
		ft_putchar('-', ret);
		ft_putchar('2', ret);
		ft_putnbr(147483648, ret);
	}
	else if (n < 0)
	{
		ft_putchar('-', ret);
		n *= -1;
		ft_putnbr(n, ret);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0', ret);
	else
	{
		ft_putnbr(n / 10, ret);
		ft_putnbr(n % 10, ret);
	}
}

void	ft_put_unsigned(unsigned int nb, int *ret)
{
	if (nb > 9)
	{
		ft_put_unsigned(nb / 10, ret);
		ft_putchar((nb % 10) + '0', ret);
	}
	else
		ft_putchar(nb + '0', ret);
}
