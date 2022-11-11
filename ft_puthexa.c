/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:59:38 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/09 16:14:21 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hexa(unsigned int nb, int *ret, char type)
{
	if (nb > 15)
	{
		ft_put_hexa(nb / 16, ret, type);
		ft_put_hexa(nb % 16, ret, type);
	}
	else if (nb >= 10 && nb <= 15)
	{
		if (type == 'l')
			ft_putchar("abcdef"[(nb % 10)], ret);
		else if (type == 'u')
			ft_putchar("ABCDEF"[(nb % 10)], ret);
	}
	else
		ft_putchar((nb + '0'), ret);
}

void	ft_putadd(unsigned long nb, int *ret)
{
	if (nb > 15)
	{
		ft_putadd(nb / 16, ret);
		ft_putadd(nb % 16, ret);
	}
	else if (nb >= 10 && nb <= 15)
	{
		ft_putchar("abcdef"[(nb % 10)], ret);
	}
	else
		ft_putchar((nb + '0'), ret);
}
