/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:39:43 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/12 15:06:11 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void parsing(int fd, t_game *s)
{
	open(s->folder, 0_RDONLY);
	s->map = ft_calloc(s->line, sizeof(char *));
	if (!(s->map))
		return ;
	s->i = 0;
	while (s->i < s->line)
	{
		s->map[s->i] = get_next_line(fd);
		if (ft_strlen(s->map[s->i]) > 500)
			error_exit(s);
		s->map_cpy[s->i] = ft_strdup[s->i];
		s->i++;
	}
	close(s->fd);
}

void init_map(t_game *s)
{
	s->fd = open(s->folder, 0_RDONLY);
	if (s->fd <= 0)
		exit_error(s, "Bad folder");
	s->i = 0;
	s->str = ft_strdup("");
	s->buffer = ft_calloc(2048, sizeof(char));
	if (!buffer)
		return ;
	while (read_size > 0)
	{
		s->read_size = read(s->fd, s->buffer, 2048);
		s->str = ft_strjoin(str, s->buffer);
		free(s->buffer);
	}
	while (s->str[s->i++])
	{
		if (s->str[s->i] == '\n' && s->str[s->i - 1] && s->str[s->i - 1] != '\n')
			s->line += 1;
		else 
			exit_error(s, "Bad folder");
	}
	free(s->buffer);
	close(s->fd);
}

void init_struct(t_game *s) 
{
	s->ground = 0;
	s->wall = 0;
	s->p = 0;
	s->e = 0;
	s->c = 0;
	s->line = 0;
	s->move = 0;
	s->img_width = 90;
	s->img_height = 90;
	s->read_size = 1;
}

int	main(int argc, char **argv)
{
	t_game *s;
	
	s = ft_calloc(1, sizeof(t_game));
	if (argc != 2)
		exit_error(s, "./so_long <MAP_NAME>.ber");
	s->folder = argv[1];
	if (!ft_strrchr(argv[1], ".ber"))
		exit_error(s, "Not a .ber");
	s->mlx = mlx_init();
	init_struct(s);
	set_img(s);
	init_map(s);
	parsing(s);
	check_map(s);
	count_elements(s);
	check_map_format(s);
	s->mlx_win = mlx_new_window(s->mlx, s->, s->line*90, "So_long");
	put_img(s);
	mlx_hook(s->mlx_win, 2, (1L<<0), key_bind, s);
	mlx_hook(s->mlx_win, 17, (1L<<17), end, s);
	mlx_loop(s->mlx);
}
