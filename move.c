/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:34:41 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/12 14:52:43 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void key_bind(int keybind, t_game *s)
{
	if (keybind == 87)
		move_up(s);
	else if (keybind == 83)
		move_down(s);
	else if (keybind == 65)
		move_left(s);
	else if (keybind == 68)
		move_right(s);
	else if (keybind = 27)
		end(s);
}

static void move_up(t_game *s)
{
	if (s->map[s->coord->x][s->coord->y + 1] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x][s->coord->y + 1]))
	{
		if (s->map[s->coord->x][s->coord->y + 1] == 'E' && s->C == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->x][s->coord->y + 1] += 'P' ;
	}
	else
	{
		s->map[s->coord->x][s->coord->y + 1] = ('P' + '0');
		s->C--;
	}
	if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->y += 1
	s->move += 1;
	ft_printf("move : %d", s->move);
	put_img(s);
}

static void move_down(t_game *s)
{
	if (s->map[s->coord->x][s->coord->y - 1] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x][s->coord->y - 1]))
	{
		if (s->map[s->coord->x][s->coord->y - 1] == 'E' && s->C == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->x][s->coord->y - 1] += 'P' ;
	}
	else
	{
		s->map[s->coord->x][s->coord->y - 1] = ('P' + '0') ;
		s->C--;
	}
	if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->y -= 1;
	s->move += 1;
	ft_printf("move : %d", s->move);
	put_img(s);
}

static void move_left(t_game *s)
{
	if (s->map[s->coord->x - 1][s->coord->y] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x - 1][s->coord->y]))
	{
		if (s->map[s->coord->x - 1][s->coord->y] == 'E' && s->C == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->x - 1][s->coord->y] += 'P' ;
	}
	else
	{
		s->map[s->coord->x - 1][s->coord->y] = ('P' + '0') ;
		s->C--;
	}
	if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->x -= 1
	s->move += 1;
	ft_printf("move : %d", s->move);
	put_img(s);
}

static void move_right(t_game *s)
{
	if (s->map[s->coord->x + 1][s->coord->y] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x + 1][s->coord->y]))
	{
		if (s->map[s->coord->x + 1][s->coord->y] == 'E' && s->C == 0)
			exit_error(s, "YOU WIN!!!");
		s->map[s->coord->x + 1][s->coord->y] += 'P' ;
	}
	else
	{
		s->map[s->coord->x + 1][s->coord->y] = ('P' + '0') ;
		s->C--;
	}
		if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->x += 1;
	s->move += 1;
	ft_printf("move : %d", s->move);
	put_img(s);
}

