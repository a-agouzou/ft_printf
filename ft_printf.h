/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:01:33 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/09 16:13:51 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c, int *ret);
void	ft_putnbr(int n, int *ret);
void	ft_putstr(char *s, int *ret);
void	ft_put_hexa(unsigned int nb, int *ret, char type);
void	ft_put_unsigned(unsigned int nb, int *ret);
void	ft_putadd(unsigned long nb, int *ret);

#endif