#include "../includes/pipex.h"

int	child_process(char **argv, char **path, char **env, int *fd)
{
	int file;
	char **spli;
	char **path2;
	int i;

	path2 = path;
	i = -1;
	file = open(argv[1], O_RDONLY);
	spli = ft_split(argv[2], ' ');
	i = verif_exist(path2, spli[0]);
	if (i == -1)
		return (3);
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file);
 	execve(path2[i], spli, env);
	return(0);
}