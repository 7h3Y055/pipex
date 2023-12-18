/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:54:06 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/18 10:11:23 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_binary_path(t_utilis *pipex, char *binary)
{
	int		i;
	char	*path;
	char	**paths;

	i = -1;
	while (pipex->envp[++i])
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
			path = &pipex->envp[i][5];
	paths = ft_split(path, ':');
	path = access_path(paths, binary);
	i = 0;
	while (paths[i] != NULL)
		free(paths[i++]);
	free(paths);
	return (path);
}

char	*access_path(char **paths, char *binary)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin("/", binary);
		path = ft_strjoin(paths[i], tmp);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	free_allocated_mem(t_utilis *pipex)
{
	int	i;

	i = 0;
	while (pipex->argument_1[i])
		free(pipex->argument_1[i++]);
	free(pipex->argument_1);
	i = 0;
	while (pipex->argument_2[i])
		free(pipex->argument_2[i++]);
	free(pipex->argument_2);
	free(pipex->binary_path_1);
	free(pipex->binary_path_2);
}
