//---3--- //
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
//---5--- //
int count_element(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if(s->map[s->i][s->j] == '0')
				s->count->ground += 1;
			else if(s->map[s->i][s->j] == '1')
				s->count->wall += 1;
			else if(s->map[s->i][s->j] == 'P')
				s->count->P += 1;
			else if(s->map[s->i][s->j] == 'E')
				s->count->E += 1;
			else if(s->map[s->i][s->j] == 'C')
				s->count->C += 1;
			s->j++;
		}
		s->i++;
	}
}


 //---1--- //
void init_struct(t_game *s) 
{
	s->ground = 0;
	s->wall = 0;
	s->P = 0;
	s->E = 0;
	s->C = 0;
	s->line = 0;
	s->move = 0;
	s->img_width = 90;
	s->img_height = 90;
	s->read_size = 1;
}
//---2--- //
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
//---4--- //
int check_map(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (!ft_strchr("01PEC", s->map[s->i][s->j]))
			exit_error();
			if (s->map[s->i][s->j] == "P")
			{
				s->coord->x = s->i;
				s->coord->y = s->j;
			}
			s->j++;
			s->count += 1;
		}
		s->i++;
		while (s->i > 0)
		{
			if (strlen(s->map[s->i] != strlen(s->map[s->i - 1])))
				exit_error(s);
			i--;
		}
	}
}
//---6--- //
void check_map_format(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if ((s->map[s->i][s->j] != '1' && (s->j == 0 || s->j == ft_strlen(s->j)))
				|| (s->map[s->i][s->j] != '1' && (s->i == 0 || s->i == ft_strlen(s->i)))
				exit_error(s, "");
			s->j++;
		}
		s->i++;
	}
	if (s->C == 0 || s->P != 1 || s-> E != 1)
		exit_error(s, "Missing Player, Collectible or Exit");
	check_map_possible(s, s->coord->x, s->coord->y);
	check_map_final(s);
}
//---7--- //
void check_map_possible(t_game *s, int i, int j)
{
	if (s->map_cpy[i - 1] != '1')
	{
		s->map_cpy[i - 1] = '1';
		check_map_possible(s, i - 1, j);
	}
	if (s->map_cpy[i + 1] != '1')
	{
		s->map_cpy[i + 1] = '1';
		check_map_possible(s, i + 1, j);
	}
	if (s->map_cpy[j - 1] != '1')
	{
		s->map_cpy[j - 1] = '1';
		check_map_possible(s, i, j - 1);
	}
	if (s->map_cpy[j - 1] != '1')
	{
		s->map_cpy[j - 1] = '1';
		check_map_possible(s, i, j + 1);
}
//---8--- //
void check_map_final(t_game *s)
{
	s->i = 0;
	while (s->map_cpy[s->i])
	{
		s->j = 0;
		while (s->map_cpy[s->i][s->j])
		{
			if (s->map_cpy[s->i][s->j] != '1')
				exit_error(s, "Map not winnable");
			s->j++;
		}
		s->i++;
	}
}
//
void exit_error(t_game *s, char *str)
{
	if (str)
		ft_printf("%s", str);
	s->i = 0;
	if (s->map)
	{
		while (s->map[i])
		{
			if (s->map[i])
				free(s->map[i]);
			i++;
		}
		free(s->map);
	}
	s->i = 0;
	if (s->map_cpy)
	{
		while (s->map_cpy[i])
		{
			if (s->map_cpy[i])
				free(s->map_cpy[i]);
			i++;
		}
		free(s->map_cpy);
	}
	free_struct(s);
	exit(1);
}
//
void free_struct(t_game *s)
{
	if (s->img->P)
		mlx_destroy_image(s->mlx, s->img->P);
	if (s->img->E)
		mlx_destroy_image(s->mlx, s->img->E);
	if (s->img->C)
		mlx_destroy_image(s->mlx, s->img->C);
	if (s->img->G)
		mlx_destroy_image(s->mlx, s->img->G);
	if (s->img->W)
		mlx_destroy_image(s->mlx, s->img->W);
	if (s->mlx_win)
		mlx_destroy_window(s->mlx, s->mlx_win);
	if (s)
		free(s);
}

//---1*--- //
void set_img(t_game *s)
{
	s->img->P = mlx_xpm_file_to_image(mlx,
		"./image/player.xpm", s->&img_width, s->&img_height)
		if (s->img->P == 0)
			exit_error(s, "Image can't be load");
	s->img->C = mlx_xpm_file_to_image(mlx,
		"./image/collectible.xpm", s->&img_width, s->&img_height)
		if (s->img->C == 0)
			exit_error(s, "Image can't be load");
	s->img->E = mlx_xpm_file_to_image(mlx,
		"./image/exit.xpm", s->&img_width, s->&img_height)
		if (s->img->E == 0)
			exit_error(s, "Image can't be load");
	s->img->W = mlx_xpm_file_to_image(mlx,
		"./image/wall.xpm", s->&img_width, s->&img_height)
		if (s->img->W == 0)
			exit_error(s, "Image can't be load");
	s->img->G = mlx_xpm_file_to_image(mlx,
		"./image/ground.xpm", s->&img_width, s->&img_height)
		if (s->img->G == 0)
			exit_error(s, "Image can't be load");
}

void set_key_bind()
{
	mlx_hook(s->mlx_win, 2, (1L<<0), key_bind, s);
	mlx_hook(s->mlx_win, 17, (1L<<17), end, s);
}
//---9---
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

void move_up(t_game *s)
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

void move_down(t_game *s)
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

void move_left(t_game *s)
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

void move_right(t_game *s)
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
void end(t_game *s)
{
	exit_error(s, "Window Closed");
}
//---8---
void put_img(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (s->map[s->i][s->j] == '1')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->W, 90, 90);
			else if (s->map[s->i][s->j] >= '0'
					&& (s->map[s->i][s->j] != 'E' || s->map[i][j] != ('E' + 'P'))
			{	
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->G, 90, 90);
				s->map[s->i][s->j] -= '0';
			}
			else if (s->map[s->i][s->j] == ('E' + 'P'))
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->E, 90, 90);
			if (s->map[s->i][s->j] == 'P')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->P, 90, 90);
			if (s->map[s->i][s->j] == 'C')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->C, 90, 90);
			s->j++;
		}
		s->i++;
	}
}
