#include "../includes/pipex.h"

void	malloc_file(int argc, char **argv, s_list *s)
{
	int i;

	i = 0;
	s->stock1 = malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
	s->stock2 = malloc(sizeof(char) * ft_strlen(argv[argc - 1]) + 1);
	while (argv[1][i])
	{
		s->stock1[i] = argv[1][i];
		i++;
	}
	s->stock1[i] = '\0';
	i = 0;
	while (argv[argc - 1][i])
	{
		s->stock2[i] = argv[argc - 1][i];
		i++;
	}
	s->stock2[i] = '\0';
}

char	**path_finish(char **env)
{
	int		i;
	char	*tmp;

	i = -1;
	while(env[++i])
	{
		tmp = ft_strjoin(env[i], "/");
		free(env[i]);
		env[i] = ft_strdup(tmp);
		free(tmp);
	}
	return (env);
}

char	**path_fct(char **env)
{
	int i;
	int y;
	char *str;
	char **spli;

	i = 0;
	y = 0;
	while (env[i])
	{
		if (memcmp(env[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	while(env[i][y] != '=')
		env[i][y++];
	str = env[i] + y + 1;
	spli = ft_split(str, ':');
	return (path_finish(spli));
}
