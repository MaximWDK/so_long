/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:38:40 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/11 00:09:54 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "minilibx/mlx.h"
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_window
{
	void	*mlx;
	void	*win;
}				t_window;

typedef struct s_map
{
	char	**map;

	int		width;
	int		height;
}				t_map;

typedef struct s_check
{
	char	**map;

	int		count_collect;
	int		count_exit;
}				t_check;

typedef struct s_img
{
	void	*player;
	void	*background;
	void	*wall;
	void	*collectible;
	void	*enemy;
	void	*exit_open;
	void	*exit_close;
	int		width_img;
	int		height_img;
}				t_img;

typedef struct s_data
{
	int			x_player;
	int			y_player;
	int			x_exit;
	int			y_exit;
	int			count_collect;
	int			count_moves;
	int			is_exit_open;
	int			is_touched;
	char		*temp;
	char		*temp2;
	char		*read;
	t_window	*window;
	t_map		*map;
	t_img		*img;
	t_check		*check;
}				t_data;

// initialize.c
void	ft_init_window(t_data *data);
void	ft_init_images(t_data *data);
void	ft_init_data(t_data *data);

// set_images.c
void	ft_set_image(t_data *data);
void	ft_set_sprite(t_data *data, int x, int y);
void	ft_update_image(t_data *data);
void	ft_update_sprite(t_data *data, int x, int y);

// moves.c
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
int		ft_keypress(int keycode, t_data *data);

// map.c
void	ft_check_map_path(t_data *data);
void	ft_check_is_perfect_rectangle(t_data *data);
int		ft_strlen_check_blanks(char *str, t_data *data);
void	ft_check_minimum_requirements(t_data *data);
void	ft_backtracking(t_data *data, int x, int y);

// utils.c

void	ft_map_to_tab(t_data *data, int fd);
char	**ft_arraycopy(char **map, t_data *data);
void	ft_algo(t_data *data);
size_t	ft_count_rows(char **map);
int		ft_is_valid_move(t_data *data, int x, int y);

// check.c
void	ft_check_file(t_data *data, char **argv);
void	ft_check_end(t_data *data);
void	ft_check_win(t_data *data, int x, int y);

// exit.c
int		ft_exit(t_data *data);
void	ft_error(char *str, t_data *data);
void	ft_game_over(t_data *data, int i);
void	ft_free_tab(char **tab);

#endif
