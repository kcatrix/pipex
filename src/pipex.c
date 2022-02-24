#include "../includes/pipex.h"

int pipex(int argc, char **argv)
{
	s_list s;
	int pid;
	int pipe[2];

	if (argc != 5)
		return (1);
	malloc_file(argc, argv, &s);
	pid = fork();
	if (pid == 0)
	{
		int x;
		read(pipe[0], &x, sizeof(x));
		printf("receive%d\n", x);
		x *= 4;
		write(pipe[1], &x, sizeof(x));
		printf("Whort%d\n", x);
		//dup2(pipe[0], STDIN_FILENO);
	}
	else
	{
		wait(NULL);
		printf("parent\n");
	}

	return (0);
}