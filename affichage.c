/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:35:57 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/04 17:29:31 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	put_other(t_game	*s)
{
	if (s->map[s->i][s->j] == 'E')
		mlx_put_image_to_window(s->mlx,
			s->mlx_win, s->img->exit, s->j * 64, s->i * 64);
	if (s->map[s->i][s->j] == 'P')
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->img->player, (s->j * 64) + 17, (s->i * 64) + 17);
	if (s->map[s->i][s->j] == 'C')
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->img->col, (s->j * 64) + 22, (s->i * 64) + 22);
	if (s->map[s->i][s->j] == (char)(69 + 80))
	{
		mlx_put_image_to_window(s->mlx,
			s->mlx_win, s->img->exit, s->j * 64, s->i * 64);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->img->player, (s->j * 64) + 17, (s->i * 64) + 17);
	}
}

void	put_decor(t_game	*s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			mlx_put_image_to_window(s->mlx,
				s->mlx_win, s->img->ground, s->j * 64, s->i * 64);
			if (s->map[s->i][s->j] == '1')
				mlx_put_image_to_window(s->mlx,
					s->mlx_win, s->img->wall, s->j * 64, s->i * 64);
			put_other(s);
			s->j++;
		}
		s->i++;
	}
}

void	set_img(t_game	*s)
{
	s->img->player = mlx_xpm_file_to_image(s->mlx,
			"./image/player.xpm", &s->img_width, &s->img_height);
	if (s->img->player == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->col = mlx_xpm_file_to_image(s->mlx,
			"./image/collectible.xpm", &s->img_width, &s->img_height);
	if (s->img->col == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->exit = mlx_xpm_file_to_image(s->mlx,
			"./image/exit.xpm", &s->img_width, &s->img_height);
	if (s->img->exit == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->wall = mlx_xpm_file_to_image(s->mlx,
			"./image/wall.xpm", &s->img_width, &s->img_height);
	if (s->img->wall == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->ground = mlx_xpm_file_to_image(s->mlx,
			"./image/ground.xpm", &s->img_width, &s->img_height);
	if (s->img->ground == 0)
		exit_error(s, "Error\nImage can't be load\n");
}
