/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:13:24 by mleonet           #+#    #+#             */
/*   Updated: 2023/08/15 23:10:46 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

void	ft_putnbr(int n, size_t	*len)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		(*len)++;
		ft_putnbr(n, len);
	}
	else
	{
		n += '0';
		write (1, &n, 1);
		(*len)++;
	}
}

void	ft_putnbr_unisgned(unsigned int n, size_t	*len)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
	{
		n += '0';
		write (1, &n, 1);
		(*len)++;
	}
}

void	ft_putnbr_hexa(unsigned int n, size_t	*len, char c)
{
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, len, c);
		ft_putnbr_hexa(n % 16, len, c);
	}
	else
	{
		(*len) += 1;
		if (c == 'x')
			ft_putchar("0123456789abcdef"[n]);
		else
			ft_putchar("0123456789ABCDEF"[n]);
	}
}

void	ft_putnbr_unsign_hexa(unsigned long long int n, size_t	*len, int c)
{
	if (n >= 16)
	{
		ft_putnbr_unsign_hexa(n / 16, len, c);
		ft_putnbr_unsign_hexa(n % 16, len, c);
	}
	else
	{
		(*len) += 1;
		ft_putchar("0123456789abcdef"[n]);
	}
}
