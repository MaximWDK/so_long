/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:58:35 by mleonet           #+#    #+#             */
/*   Updated: 2023/05/09 14:14:25 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			size;

	i = -1;
	if (dstsize != 0)
	{
		while (src[++i] != '\0' && i < (dstsize - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	size = ft_strlen(src);
	return (size);
}
