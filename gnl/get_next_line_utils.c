/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:40:12 by mleonet           #+#    #+#             */
/*   Updated: 2023/11/22 13:29:30 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize)
{
	size_t			i;
	size_t			size;

	i = -1;
	if (!src || !dst)
		return (0);
	if (dstsize != 0)
	{
		while (src[++i] != '\0' && i < (dstsize - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	size = ft_strlen_gnl(src);
	return (size);
}

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_the_line(char *stash, int line_length, int add)
{
	char	*line;

	line = malloc(sizeof(char) * (line_length + 1 + add));
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(line, stash, line_length + 1 + add);
	return (line);
}

char	*get_remainder(char *stash, int line_length)
{
	int		len;
	char	*remainder;

	len = ft_strlen_gnl(stash + line_length + 1);
	remainder = malloc(sizeof(char) * (len + 1));
	if (!remainder)
		return (NULL);
	ft_strlcpy_gnl(remainder, stash + line_length + 1, len + 1);
	return (remainder);
}
