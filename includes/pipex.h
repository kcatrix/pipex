#ifndef PIPEX_H
# define PIPEX_H

#include "macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	t_list{
	char *stock1;
	char *stock2;
}				s_list;

int		pipex(int argc, char **argv);
char	Get_error(int i);
void	malloc_file(int argc, char **argv, s_list *s);

#endif