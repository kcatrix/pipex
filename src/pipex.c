#include "../includes/pipex.h"

int pipex(int argc, char **argv, char **env)
{
	int pid;
	int fd[2];
	char **path;
	char **spli;
	int i;
	int file;
	char x[50];

	i = -1;
	file = 0;
	//if (verif_file(argc, argv) != 0)
	//	return(verif_file(argc, argv));
	path = path_fct(env);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		return(3);
	if (pid == 0)
	{
		if (child_process(argv, path, env, fd) == 3)
			return 3;
	}
	else
	{
		wait(NULL);
		file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(fd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		spli = ft_split(argv[3], ' ');
		i = verif_exist(path, spli[0]);
		if (i == -1)
			return (3);
		close(fd[0]);
		close(fd[1]);
		close(file);
		printf("%s\n", spli[0]);
		printf("%s\n", spli[1]);
		printf("%s\n", path[0]);
		printf("%s\n", path[1]);
		execve(path[i], spli, env);
	}
	return (0);
}