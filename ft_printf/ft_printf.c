/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:45 by mleonet           #+#    #+#             */
/*   Updated: 2023/08/15 23:10:41 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	ft_check_is_in(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i')
		return (1);
	else if (c == 'x' || c == 'X' || c == 'u' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	ft_format(char c, va_list lst, size_t i)
{
	if (c == 'c')
		i += ft_putchar(va_arg(lst, int));
	else if (c == 's')
		i += ft_putstr(va_arg(lst, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(lst, int), &i);
	else if (c == 'x' || c == 'X')
		ft_putnbr_hexa(va_arg(lst, unsigned int), &i, c);
	else if (c == 'u')
		ft_putnbr_unisgned(va_arg(lst, unsigned int), &i);
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		ft_putnbr_unsign_hexa(va_arg(lst, unsigned long long int), &i, 1);
	}
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_check_is_in(str[i + 1]) == 1)
		{
			len = ft_format(str[i + 1], lst, len);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
