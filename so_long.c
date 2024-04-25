/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:39:43 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/25 16:55:31 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void parsing(t_game *s)
{
	s->fd = open(s->folder, O_RDONLY);
	s->map = ft_calloc(s->line + 1, sizeof(char *));
	if (!(s->map))
		return ;
	s->map_cpy = ft_calloc(s->line + 1, sizeof(char *));
	if (!s->map_cpy)
		return ;
	s->i = 0;
	while (s->i < s->line)
	{
		s->map[s->i] = ft_strtrim(get_next_line(s->fd), "\n");
		if (s->map[s->i] == NULL)
			exit_error(s, "Error\n");
		if (ft_strlen(s->map[s->i]) > 500)
			exit_error(s, "Error\n");
		s->map_cpy[s->i] = ft_strdup(s->map[s->i]);
		s->i++;
	}
	get_next_line(s->fd);
	close(s->fd);
}

void	init_map(t_game *s)
{
	s->fd = open(s->folder, O_RDONLY);
	if (s->fd <= 0)
		exit_error(s, "Bad folder");
	s->i = 1;
	s->str = ft_strdup("");
	s->buffer = ft_calloc(1025, sizeof(char));
	if (!s->buffer)
		return ;
	while (s->read_size > 0)
	{
		s->read_size = read(s->fd, s->buffer, 1024);
		if (s->read_size > 0)
			s->str = ft_strjoin(s->str, s->buffer);
	}
	while (s->i++ < (int)ft_strlen(s->str))
	{
		if (s->str[s->i] == '\n' && s->str[s->i - 1] && s->str[s->i - 1] != '\n')
			s->line++;
		else if (s->str[s->i] == '\n' && s->str[s->i - 1] == '\n')
			break;
	}
	close(s->fd);
	ft_printf("\n|%d|\n", s->str[s->i - 2]);
	if (s->str[s->i - 2] != '\n')
	{
		exit_error(s, "Bad folderr");
	}
}

void init_struct(t_game *s) 
{
	s->ground = 0;
	s->wall = 0;
	s->player = 0;
	s->ext = 0;
	s->col = 0;
	s->line = 0;
	s->move = 0;
	s->img_width = 90;
	s->img_height = 90;
	s->read_size = 1;
	s->img = ft_calloc(1, sizeof(*s->img));
	if (!s->img)
		exit_error(s, "Error\n");
	s->coord = ft_calloc(1, sizeof(*s->coord));
	if (!s->coord)
		exit_error(s, "Error\n");
}

static int str_r_search(char *str, char *search, t_game *s)
{
	s->i = ft_strlen(str);
	s->j = ft_strlen(search);
	while (s->j > 0 && str[s->i])
	{
		if (str[s->i] != search[s->j])
			return (0);
		s->i--;
		s->j--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*s;

	s = ft_calloc(1, sizeof(t_game));
	if (s == NULL)
		exit_error(s, "Error\n");
	if (argc != 2)
		exit_error(s, "./so_long <MAP_NAME>.ber");
	s->folder = argv[1];
	if (!str_r_search(argv[1], ".ber", s))
		exit_error(s, "Not a .ber");
	init_struct(s);
	init_map(s);
	parsing(s);
	check_map(s);
	count_element(s);
	check_map_format(s);
	s->mlx = mlx_init();
	if (s->mlx == NULL)
		exit_error(s, "Error\n");
	set_img(s);
	s->mlx_win = mlx_new_window(s->mlx,
			ft_strlen(s->map[0]) * 90, s->line * 90, "So_long");
	put_img(s);
	mlx_hook(s->mlx_win, 2, (1L << 0), key_bind, s);
	mlx_hook(s->mlx_win, 17, (1L << 17), end, s);
	mlx_loop(s->mlx);
}
