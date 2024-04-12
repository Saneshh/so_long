/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:47:36 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/12 15:00:42 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	void	*w;
	void	*p;
	void	*c;
	void	*e;
	void	*g;
}	t_img;

typedef	struct s_game
{
	int		fd;
	int		i;
	int		j;
	int		c;
	int		p;
	int		e;
	int		wall;
	int		ground;
	int		line;
	int		move;
	int		read_size;
	char	**map_cpy;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	int		img_width;
	int		img_height;
	t_coord	*coord;
	t_img	*img;
}	t_game;

	void	parsing(t_game *s);
	void	count_element(t_game *s);
	void	init_struct(t_game *s);
	void	init_map(t_game *s);
	void	check_map(t_game *s);
	void	check_map_format(t_game *s);
	void	exit_error(t_game *s, char *str);
	void	set_img(t_game *s);
	void	key_bind(t_game *s);
	void	end(t_game *s);
	void	put_img(t_game *s);
#endif
