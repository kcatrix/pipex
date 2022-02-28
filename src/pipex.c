#include "../includes/pipex.h"

int pipex(int argc, char **argv, char **env)
{
	s_list s;
	int pid;
	int fd[2];
	char **path;
	int i;

	i = -1;
	/*if (argc != 5)
		return (1);*/
	path = path_fct(env);
	while (path[++i])
		printf("%s\n", path[i]);
	/*pipe(fd);
	close(fd[1]);
	malloc_file(argc, argv, &s);
	pid = fork();
	if (pid == -1)
		return(2);
	if (pid == 0)
	{
		//int file = open("test.txt", O_RDWR | O_CREAT, 0777);
		char *path;
		char **ar;
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ar = argv + 1;
		path = ft_strjoin("/bin/", ar[0]);
		execve(path, ar, env);
		free(path);
		read(pip[0], &x, sizeof(x));
		printf("receive%d\n", x);
		x += 4;
		write(pip[1], &x, sizeof(x));
		printf("Whort%d\n", x);
		//dup2(pipe[0], STDIN_FILENO);
		//close(pip[1]);
	}
	else
	{
		/*wait(NULL);
		dup2(pip[1], STDOUT_FILENO);
		read(pip[0], &y, sizeof(y));
		printf("receive%d\n", y);*/
		/*y *= 3;
		write(pip[1], &y, sizeof(y));	
		read(pip[0], &y, sizeof(y));
		printf("parent%d\n", y);
	}*/

	return (0);
}