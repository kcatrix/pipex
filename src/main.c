#include "../includes/pipex.h"

int main(int argc, char **argv, char **env)
{
	int i;
	
	i = pipex(argc, argv, env);
	if (i != 0)
		Get_error(i);
	return (0);
}
