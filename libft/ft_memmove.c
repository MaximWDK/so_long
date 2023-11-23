/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:18:05 by mleonet           #+#    #+#             */
/*   Updated: 2023/04/06 14:48:02 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	size_t				j;
	unsigned char		*d;
	const unsigned char	*s;

	i = -1;
	j = len + 1;
	d = dst;
	s = src;
	if (!src && !dst)
		return (NULL);
	if (dst > src)
	{
		while (--j > 0)
			d[j - 1] = s[j - 1];
	}
	else
	{
		while (++i < len)
			d[i] = s[i];
	}
	return (dst);
}
