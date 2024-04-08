void parsing(int fd)
{
	t_parse *s;
	int i;

	i = 0;
	while (get_next_line(fd))
	{
		s->line[i] = get_next_line(fd);
		i++;
	}
}
int check_map(t_parse *s)
{
	int	i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s->line[i])
	{
		j = 0;
		while (s->line[i][j])
		{
			if (!ft_strncmp(s->line[i][j], "01PEC", 5))
			exit_error();
			j++;
			s->count += 1;
		}
		i++;
	}
}
