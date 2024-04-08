void parsing(int fd, t_game *s)
{
	int i;

	i = 0;
	while (get_next_line(fd))
	{
		s->map[i] = ft_split(get_next_line(fd), ' ');
		i++;
	}
}

int count_element(t_game *s, int i, int j)
{
	if(s->map[i][j] == '0')
		s->count->ground += 1;
	else if(s->map[i][j] == '1')
		s->count->wall += 1;
	else if(s->map[i][j] == 'P')
		s->count->P += 1;
	else if(s->map[i][j] == 'E')
		s->count->E += 1;
	else if(s->map[i][j] == 'C')
		s->count->C += 1;
}
void init_struct(t_game *s)
{
	s->count->ground = 0;
	s->count->wall = 0;
	s->count->P = 0;
	s->count->E = 0;
	s->count->C = 0;
}
int check_map(t_game *s)
{
	int	i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (!ft_strncmp(s->map[i][j], "01PEC", 5))
			exit_error();
			j++;
			s->count += 1;
		}
		i++;
		while (i > 0)
		{
			if (strlen(s->map[i] != strlen(s->map[i - 1])))
				exit_error();
		}
	}
}
void exit_error()
{

	exit(1);
}
