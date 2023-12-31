/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:40:09 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/11 18:17:23 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (argc != 2)
		ft_error("Error\nWrong Number Of Arguments\n", &data);
	ft_check_file(&data, argv);
	ft_check_map_path(&data);
	ft_init_window(&data);
	ft_init_images(&data);
	ft_set_image(&data);
	mlx_hook(data.window->win, 2, 0, ft_keypress, &data);
	mlx_hook(data.window->win, 17, 0, ft_exit, &data);
	mlx_loop(data.window->mlx);
	return (0);
}
