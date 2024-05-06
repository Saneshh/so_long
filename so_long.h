/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:47:36 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/04 17:35:35 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_image
{
	void	*wall;
	void	*player;
	void	*col;
	void	*exit;
	void	*ground;
	int	img_width;
	int	img_height;
}	t_image;

typedef struct s_buffer
{
	char *str;
	char *buffer;
}	t_buffer;

typedef struct s_game
{
	int		fd;
	int		col;
	int		player;
	int		ext;
	int		wall;
	int		ground;
	int		line;
	int		move;
	char	*folder;
	char	**map_cpy;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	t_buffer *buf;
	t_coord	coord;
	t_image	*img;
}	t_game;

void	parsing(t_game *s, int i, int j);
void	init_struct(t_game *s, int i);
void	init_map(t_game *s, int i);
void	check_map(t_game *s, int i, int j);
void	check_map_format(t_game *s, int i, int j);
void	exit_error(t_game *s, char *str);
void	set_img(t_game *s);
int		key_bind(int keybind, t_game *s);
int		end(t_game *s);
void	put_decor(t_game *s);
void	print_move(t_game *s);
#endif
