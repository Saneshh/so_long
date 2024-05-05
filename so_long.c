/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:39:43 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/04 17:31:10 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static	int	check_line(t_game *s, int i)
{
	int read_size;

	read_size = 1;
	while (read_size > 0)
        {
                read_size = read(s->fd, s->buf->buffer, 1024);
                s->buf->buffer[read_size] = 0;
                if (read_size > 0)
                        s->buf->str = ft_strjoin(s->buf->str, s->buf->buffer);
                if (!s->buf->str)
                        exit_error(s, "Error\nAlloc error\n");
        }
	if (ft_strlen(s->buf->str) < 2)
		exit_error(s, "Error\nMap too short\n");
	while (i++ < (int)ft_strlen(s->buf->str))
	{
		if (s->buf->str[i] == '\n' && s->buf->str[i - 1]
			&& s->buf->str[i - 1] != '\n')
			s->line++;
		else if (s->buf->str[i] == '\n' && s->buf->str[i - 1] == '\n')
			exit_error(s, "Error\nToo much line return\n");
	}
	return (i);
}

void	init_map(t_game *s, int i)
{
	s->fd = open(s->folder, O_RDONLY);
	if (s->fd <= 0)
		exit_error(s, "Error\nFd can't be open\n");
	i = 0;
	s->buf->str = ft_strdup("");
	if (!s->buf->str)
		exit_error(s, "Error\nAlloc error\n");
	s->buf->buffer = ft_calloc(1025, sizeof(char));
	if (!s->buf->buffer)
		exit_error(s, "Error\nAlloc error\n");
	i = check_line(s, i);
	close(s->fd);
	if (s->buf->str[i - 2] != '\n')
		exit_error(s, "Error\nNo return at the end\n");
}

static	int	str_r_search(char *str, char *search)
{
	int	i;
	int	j;
	
	i = ft_strlen(str) - 1;
	j = ft_strlen(search) - 1;
	while (j >= 0 && i >= 0)
	{
		if (str[i] != search[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

void	init_struct(t_game	*s, int i)
{
	s->ground = 0;
	s->wall = 0;
	s->player = 0;
	s->ext = 0;
	s->col = 0;
	s->line = 0;
	s->move = 0;
	s->buf = ft_calloc(1, sizeof(*s->buf));
	if (!s->buf)
		exit_error(s, "Error\nAlloc erro\n");
	s->img = ft_calloc(1, sizeof(*s->img));
	if (!s->img)
		exit_error(s, "Error\nAlloc error\n");
	s->img->img_width = 64;
	s->img->img_height = 64;
	if (!str_r_search(s->folder, ".ber"))
		exit_error(s, "Error\nNot a .ber\n");
	init_map(s, i);
}

int	main(int argc, char **argv)
{
	t_game	*s;
	int	i;
	int	j;

	i = 0;
	j = 0;
	s = ft_calloc(1, sizeof(t_game));
	if (s == NULL)
		exit_error(s, "Error\nAlloc error\n");
	if (argc != 2)
		exit_error(s, "Error\n./so_long <MAP_NAME>.ber\n");
	s->folder = argv[1];
	init_struct(s, i);
	parsing(s, i, j);
	check_map(s, i, j);
	check_map_format(s, i, j);
	s->mlx = mlx_init();
	if (s->mlx == NULL)
		exit_error(s, "Error\nSet display...\n");
	set_img(s);
	s->mlx_win = mlx_new_window(s->mlx,
			ft_strlen(s->map[0]) * 64, s->line * 64, "So_long");
	put_decor(s);
	mlx_hook(s->mlx_win, 2, (1L << 0), key_bind, s);
	mlx_hook(s->mlx_win, 17, (1L << 17), end, s);
	mlx_loop(s->mlx);
}
