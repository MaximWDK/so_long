/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:43 by mleonet           #+#    #+#             */
/*   Updated: 2023/05/11 13:48:18 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findlen(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_convert(int n, char *str, int len)
{
	int	save;

	save = n;
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		save = 147483648;
	}
	if (save < 0)
	{
		str[0] = '-';
		save = save * -1;
	}
	while (save > 0)
	{
		str[--len] = save % 10 + '0';
		save /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_findlen(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_convert(n, str, len);
	return (str);
}
