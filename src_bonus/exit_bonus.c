/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:07:20 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/11 10:46:16 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->window->mlx, data->window->win);
	ft_free_tab(data->map->map);
	ft_free_tab(data->check->map);
	free(data->map);
	free(data->img);
	free(data->window);
	free(data->check);
	exit(EXIT_SUCCESS);
}

void	ft_game_over(t_data *data, int i)
{
	mlx_destroy_window(data->window->mlx, data->window->win);
	ft_free_tab(data->map->map);
	ft_free_tab(data->check->map);
	free(data->map);
	free(data->img);
	free(data->window);
	free(data->check);
	if (i == 1)
		ft_printf("You lost!\n");
	else
		ft_printf("You won!\n");
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str, t_data *data)
{
	ft_printf("%s", str);
	if (data->map->map)
		ft_free_tab(data->map->map);
	if (data->check->map)
		ft_free_tab(data->check->map);
	if (data->read)
		free(data->read);
	if (data->img)
		free(data->img);
	if (data->window)
		free(data->window);
	if (data->map)
		free(data->map);
	if (data->check)
		free(data->check);
	exit(EXIT_SUCCESS);
}

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
