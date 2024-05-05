/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:35:57 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/04 17:29:31 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	put_other(t_game	*s, int i, int j)
{
	if (s->map[i][j] == 'E')
		mlx_put_image_to_window(s->mlx,
			s->mlx_win, s->img->exit, j * 64, i * 64);
	if (s->map[i][j] == 'P')
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->img->player, (j * 64) + 17, (i * 64) + 17);
	if (s->map[i][j] == 'C')
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->img->col, (j * 64) + 22, (i * 64) + 22);
	if (s->map[i][j] == (char)(69 + 80))
	{
		mlx_put_image_to_window(s->mlx,
			s->mlx_win, s->img->exit, j * 64, i * 64);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->img->player, (j * 64) + 17, (i * 64) + 17);
	}
}

void	put_decor(t_game	*s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			mlx_put_image_to_window(s->mlx,
				s->mlx_win, s->img->ground, j * 64, i * 64);
			if (s->map[i][j] == '1')
				mlx_put_image_to_window(s->mlx,
					s->mlx_win, s->img->wall, j * 64, i * 64);
			put_other(s, i, j);
			j++;
		}
		i++;
	}
}

void	set_img(t_game	*s)
{
	s->img->player = mlx_xpm_file_to_image(s->mlx,
			"./image/player.xpm", &s->img->img_width, &s->img->img_height);
	if (s->img->player == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->col = mlx_xpm_file_to_image(s->mlx,
			"./image/collectible.xpm", &s->img->img_width, &s->img->img_height);
	if (s->img->col == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->exit = mlx_xpm_file_to_image(s->mlx,
			"./image/exit.xpm", &s->img->img_width, &s->img->img_height);
	if (s->img->exit == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->wall = mlx_xpm_file_to_image(s->mlx,
			"./image/wall.xpm", &s->img->img_width, &s->img->img_height);
	if (s->img->wall == 0)
		exit_error(s, "Error\nImage can't be load\n");
	s->img->ground = mlx_xpm_file_to_image(s->mlx,
			"./image/ground.xpm", &s->img->img_width, &s->img->img_height);
	if (s->img->ground == 0)
		exit_error(s, "Error\nImage can't be load\n");
}
