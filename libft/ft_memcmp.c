/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:36:14 by mleonet           #+#    #+#             */
/*   Updated: 2023/05/09 19:43:16 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = -1;
	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (++i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
	}
	return (0);
}
