/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:01:09 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/08 18:00:26 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_file(t_data *data, char **argv)
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

void	ft_check_end(t_data *data)
{
	if (data->check->count_collect != data->count_collect
		|| data->check->count_exit != 1)
		ft_error("Error: Map can't be completed\n");
}

void	ft_check_win(t_data *data, int x, int y)
{
	if (data->count_collect == 0 && data->map->map[y][x] == 'E')
		ft_game_over(data);
}
