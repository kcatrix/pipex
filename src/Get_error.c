#include "../includes/pipex.h"

char	Get_error(int i)
{
	if (i == 1)
		write(2, ERROR1, ft_strlen(ERROR1));
	if (i == 2)
		write(2, ERROR2, ft_strlen(ERROR2));
	if (i == 3)
		write(2, ERROR3, ft_strlen(ERROR3));
	exit(0);
}