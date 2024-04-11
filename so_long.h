/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:47:36 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/08 13:29:05 by hsolet           ###   ########.fr       */
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
	void *W;
	void *P;
	void *C;
	void *E;
	void *G;
} t_img

typedef	struct s_game
{
	int fd;
	int i;
	int j;
	int C;
	int	P;
	int E;
	int wall;
	int ground;
	int line;
	int move;
	char **map_cpy;
	char **map;
	void *mlx;
	void *mlx_win;
	void *img_ptr;
	t_count *count;
	t_coord *coord;
	t_img *img;
} t_game;

#endif
