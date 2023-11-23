/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:50:28 by mleonet           #+#    #+#             */
/*   Updated: 2023/05/09 19:42:48 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = -1;
	str = (const unsigned char *) s;
	while (++i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *) &str[i]);
	}
	return (NULL);
}
