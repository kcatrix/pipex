#include "../includes/pipex.h"

char	Get_error(int i)
{
	if (i == 1)
		write(2, ERROR1, ft_strlen(ERROR1));
	exit(0);
}