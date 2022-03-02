#ifndef PIPEX_H
# define PIPEX_H

#include "macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	t_list{
	char *stock1;
	char *stock2;
}				s_list;

int		pipex(int argc, char **argv, char **env);
char	Get_error(int i);
char	**path_fct(char **env);
int		verif_file(int argc ,char **argv);
int 	verif_exist(char **path, char *argv);
void	malloc_file(int argc, char **argv, s_list *s);
int		child_process(char **argv, char **path, char **env, int *fd);

#endif