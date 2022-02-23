#include "../includes/pipex.h"

char	Get_error(int i)
{
	if (i == 1)
		write(1, ERROR1, ft_strlen(ERROR1));
	exit(0);
}

int main(int argc, char **argv)
{
	int i;

	i = pipex(argc);
	Get_error(i);
	return (0);
}
