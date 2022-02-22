/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:37:59 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/22 14:41:06 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	child_process(char **argv, char **path, char **env, int *fd)
{
	int		file;
	char	**spli;
	char	**path2;
	int		i;

	path2 = path;
	i = -1;
	file = open(argv[1], O_RDONLY);
	spli = ft_split(argv[2], ' ');
	i = verif_exist(path2, spli[0]);
	if (i == -1)
		return (3);
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file);
	execve(path2[i], spli, env);
	return (0);
}

int	parent_process(char **argv, char **path, char **env, int *fd)
{
	int		file;
	char	**spli;
	char	**path2;
	int		i;

	wait(NULL);
	path2 = path;
	i = -1;
	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	spli = ft_split(argv[3], ' ');
	i = verif_exist(path2, spli[0]);
	if (i == -1)
		return (3);
	close(fd[0]);
	close(fd[1]);
	close(file);
	execve(path2[i], spli, env);
	return (0);
}
