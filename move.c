/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:34:41 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/26 14:45:18 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static	void	move_right(t_game *s)
{
	if (s->map[s->coord->y][s->coord->x + 1] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord->y][s->coord->x + 1] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->y][s->coord->x + 1] = (char)(80 + 69);
	}
	else if (s->map[s->coord->y][s->coord->x + 1] == 'C')
	{
		s->map[s->coord->y][s->coord->x + 1] = 'P';
		s->col--;
	}
	else
		s->map[s->coord->y][s->coord->x + 1] = 'P';
	if (s->map[s->coord->y][s->coord->x] == (char)(80 + 69))
		s->map[s->coord->y][s->coord->x] = 'E';
	else
		s->map[s->coord->y][s->coord->x] = '0';
	s->coord->x += 1;
	put_decor(s);
}

static	void	move_left(t_game *s)
{
	if (s->map[s->coord->y][s->coord->x - 1] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord->y][s->coord->x - 1] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->y][s->coord->x - 1] = (char)(80 + 69);
	}
	else if (s->map[s->coord->y][s->coord->x - 1] == 'C')
	{
		s->map[s->coord->y][s->coord->x - 1] = 'P' ;
		s->col--;
	}
	else
		s->map[s->coord->y][s->coord->x - 1] = 'P' ;
	if (s->map[s->coord->y][s->coord->x] == (char)(80 + 69))
		s->map[s->coord->y][s->coord->x] = 'E';
	else
		s->map[s->coord->y][s->coord->x] = '0';
	s->coord->x -= 1;
	put_decor(s);
}

static	void	move_up(t_game *s)
{
	if (s->map[s->coord->y - 1][s->coord->x] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord->y - 1][s->coord->x] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->y - 1][s->coord->x] = (char)(80 + 69);
	}
	else if (s->map[s->coord->y - 1][s->coord->x] == 'C')
	{
		s->map[s->coord->y - 1][s->coord->x] = 'P';
		s->col--;
	}
	else
		s->map[s->coord->y - 1][s->coord->x] = 'P';
	if (s->map[s->coord->y][s->coord->x] == (char)(80 + 69))
		s->map[s->coord->y][s->coord->x] = 'E';
	else
		s->map[s->coord->y][s->coord->x] = '0';
	s->coord->y -= 1;
	put_decor(s);
}

static	void	move_down(t_game *s)
{
	if (s->map[s->coord->y + 1][s->coord->x] == '1')
		return ;
	s->move += 1;
	ft_printf("move : %d\n", s->move);
	if (s->map[s->coord->y + 1][s->coord->x] == 'E')
	{
		if (s->col == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->y + 1][s->coord->x] = (char)(80 + 69);
	}
	else if (s->map[s->coord->y + 1][s->coord->x] == 'C')
	{
		s->map[s->coord->y + 1][s->coord->x] = 'P' ;
		s->col--;
	}
	else
		s->map[s->coord->y + 1][s->coord->x] = 'P' ;
	if (s->map[s->coord->y][s->coord->x] == (char)(80 + 69))
		s->map[s->coord->y][s->coord->x] = 'E';
	else
		s->map[s->coord->y][s->coord->x] = '0';
	s->coord->y += 1;
	put_decor(s);
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
