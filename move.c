/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:34:41 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/08 15:03:48 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static	void	move_right(t_game *s)
{
	if (s->map[s->coord.y][s->coord.x + 1] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord.y][s->coord.x + 1] == 'C')
		s->col--;
	if (s->map[s->coord.y][s->coord.x + 1] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!\n");
		s->map[s->coord.y][s->coord.x + 1] = (char)(80 + 69);
	}
	else
		s->map[s->coord.y][s->coord.x + 1] = 'P';
	print_move(s);
	s->coord.x += 1;
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->player,
		(s->coord.x * 64) + 17, (s->coord.y * 64) + 17);
}

static	void	move_left(t_game *s)
{
	if (s->map[s->coord.y][s->coord.x - 1] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord.y][s->coord.x - 1] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!\n");
		s->map[s->coord.y][s->coord.x - 1] = (char)(80 + 69);
	}
	else if (s->map[s->coord.y][s->coord.x - 1] == 'C')
	{
		s->map[s->coord.y][s->coord.x - 1] = 'P' ;
		s->col--;
	}
	else
		s->map[s->coord.y][s->coord.x - 1] = 'P' ;
	print_move(s);
	s->coord.x -= 1;
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->player,
		(s->coord.x * 64) + 17, (s->coord.y * 64) + 17);
}

static	void	move_up(t_game *s)
{
	if (s->map[s->coord.y - 1][s->coord.x] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord.y - 1][s->coord.x] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!\n");
		s->map[s->coord.y - 1][s->coord.x] = (char)(80 + 69);
	}
	else if (s->map[s->coord.y - 1][s->coord.x] == 'C')
	{
		s->map[s->coord.y - 1][s->coord.x] = 'P';
		s->col--;
	}
	else
		s->map[s->coord.y - 1][s->coord.x] = 'P';
	print_move(s);
	s->coord.y -= 1;
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->player,
		(s->coord.x * 64) + 17, (s->coord.y * 64) + 17);
}

static	void	move_down(t_game *s)
{
	if (s->map[s->coord.y + 1][s->coord.x] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord.y + 1][s->coord.x] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!\n");
		s->map[s->coord.y + 1][s->coord.x] = (char)(80 + 69);
	}
	else if (s->map[s->coord.y + 1][s->coord.x] == 'C')
	{
		s->map[s->coord.y + 1][s->coord.x] = 'P' ;
		s->col--;
	}
	else
		s->map[s->coord.y + 1][s->coord.x] = 'P' ;
	print_move(s);
	s->coord.y += 1;
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->player,
		(s->coord.x * 64) + 17, (s->coord.y * 64) + 17);
}

int	key_bind(int keybind, t_game *s)
{
	if (keybind == 119)
		move_up(s);
	else if (keybind == 115)
		move_down(s);
	else if (keybind == 97)
		move_left(s);
	else if (keybind == 100)
		move_right(s);
	else if (keybind == 65307)
		end(s);
	return (0);
}
