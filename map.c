/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:50:54 by mleonet           #+#    #+#             */
/*   Updated: 2023/11/23 16:59:20 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Wrong Map Path\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: Wrong Map Name\n");
		exit(EXIT_FAILURE);
	}
	ft_map_to_tab(data, fd);
	close(fd);
}

void	ft_map_to_tab(t_data *data, int fd)
{
	char	*final;
	char	*temp;
	int		i;

	i = 0;
	final = NULL;
	temp = get_next_line(fd);
	if (!temp)
		ft_error("Error: Empty file\n");
	final = ft_strdup(temp);
	while (temp)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
		if (temp)
			final = ft_strjoin(final, temp);
	}
	data->map->map = ft_split(final, '\n');
	free(final);
	if (!data->map->map)
		ft_error("Error: Creating Map Failed\n");
	data->map->width = ft_strlen(data->map->map[0]) * 32;
	data->map->height = i * 32;
}
