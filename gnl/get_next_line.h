/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:40:14 by mleonet           #+#    #+#             */
/*   Updated: 2023/11/22 13:09:20 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_and_insert_stash(int fd, char *stash);
int		is_newline(char *str);
char	*add_to_stash(char *stash, char *buf);
char	*extract_line(char **stash);
char	*extract_line_utils(char **stash, int index, int add);
size_t	ft_strlen_gnl(char *str);
size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize);
char	*get_the_line(char *stash, int line_length, int add);
char	*get_remainder(char *stash, int line_length);

#endif