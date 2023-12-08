/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:40:11 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/08 18:00:59 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**ft_arraycopy(char **map)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (ft_count_rows(map) + 1));
	if (!new_map)
		ft_error("Error: Malloc Failed\n");
	while (map[i])
	{
		j = -1;
		new_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!new_map[i])
			ft_error("Error: Malloc Failed\n");
		while (map[i][++j])
			new_map[i][j] = map[i][j];
		new_map[i++][j] = '\0';
	}
	new_map[i] = NULL;
	return (new_map);
}

void	ft_algo(t_data *data)
{
	ft_backtracking(data, data->x_player, data->y_player);
	ft_check_end(data);
}

size_t	ft_count_rows(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_is_valid_move(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == '1')
		return (0);
	else if (data->map->map[y][x] == 'E')
	{
		if (data->count_collect == 0)
			return (1);
		else
			return (0);
	}
	return (1);
}
