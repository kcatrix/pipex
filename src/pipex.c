#include "../includes/pipex.h"

int pipex(int argc, char **argv, char **env)
{
	int pid;
	int fd[2];
	char **path;
	char **spli;
	int i;

	i = -1;
	//if (verif_file(argc, argv) != 0)
	//	return(verif_file(argc, argv));
	path = path_fct(env);
	
	//printf("path[i] = %s", path[i]);
	//while (path[++i])
	//	printf("%s\n", path[i]);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		return(3);
	if (pid == 0)
	{
		spli = ft_split(argv[2], ' ');
		i = verif_exist(path, spli[0]);
		if (i == -1)
			return (3);
		//dup2(fd[0], STDIN_FILENO);
		//close(fd[0]);
		printf("path[i] %s\n", path[i]);
		printf("argv[1] %s\n", argv[0]);
		//la cmd | les args
		
		printf("spli[0] = %s\n", spli[0]);
		printf("spli[1] = %s\n", spli[1]);
 		execve(path[i], spli, env);
		//free(path);
		//dup2(pipe[0], STDIN_FILENO);
		//close(pip[1]);
	}
	else
	{
		wait(NULL);
		printf("ok\n");
		/*wait(NULL);
		//read(pip[0], &x, sizeof(x));
		//int file = open("test.txt", O_RDWR | O_CREAT, 0777);
		dup2(pip[1], STDOUT_FILENO);
		read(pip[0], &y, sizeof(y));
		printf("receive%d\n", y);*/
		/*y *= 3;
		write(pip[1], &y, sizeof(y));	
		read(pip[0], &y, sizeof(y));
		printf("parent%d\n", y);*/
	}

	return (0);
}