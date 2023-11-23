/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:11:01 by mleonet           #+#    #+#             */
/*   Updated: 2023/05/09 18:20:46 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		sizesrc;
	size_t		sizedst;
	int			i;
	int			res;

	sizesrc = ft_strlen(src);
	sizedst = ft_strlen(dst);
	i = 0;
	res = 0;
	if (sizedst < dstsize)
		res = sizesrc + sizedst;
	else
		res = sizesrc + dstsize;
	while (src[i] && (sizedst + 1) < dstsize)
		dst[sizedst++] = src[i++];
	dst[sizedst] = '\0';
	return (res);
}
