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