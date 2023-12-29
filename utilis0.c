/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:52:41 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/18 09:52:43 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_utilis *pipex)
{
	dup2(pipex->infile_fd, 0);
	close(pipex->infile_fd);
	close(pipex->pipe_fd[0]);
	dup2(pipex->pipe_fd[1], 1);
	close(pipex->pipe_fd[1]);
	execve(pipex->binary_path_1, pipex->argument_1, pipex->envp);
}

void	parent(t_utilis *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], 0);
	dup2(pipex->outfile_fd, 1);
	close(pipex->outfile_fd);
	execve(pipex->binary_path_2, pipex->argument_2, pipex->envp);
}

void	init_t_utilis(t_utilis *pipex, int argc, char const **argv, char **envp)
{
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->infile_fd = open(pipex->infile, O_RDONLY);
	pipex->outfile_fd = open(pipex->outfile, 01 | O_TRUNC | O_CREAT, 0777);
	pipex->envp = envp;
	pipex->argument_1 = ft_split(argv[2], ' ');
	pipex->argument_2 = ft_split(argv[3], ' ');
	pipex->binary_path_1 = get_binary_path(pipex, pipex->argument_1[0]);
	pipex->binary_path_2 = get_binary_path(pipex, pipex->argument_2[0]);
	pipe(pipex->pipe_fd);
}

void	check_t_utilis(t_utilis *pipex)
{
	if (pipex->infile_fd == -1)
		perror(pipex->infile);
	if (!pipex->binary_path_1 || !pipex->binary_path_2)
		check_t_utilis_helper(pipex, "command not found: ");
	if (pipex->infile_fd == -1 || !pipex->binary_path_1 || \
			!pipex->binary_path_2)
	{
		free_allocated_mem(pipex);
		exit(1);
	}
}

void	check_t_utilis_helper(t_utilis *pipex, char *error_msg)
{
	if (!pipex->binary_path_1 && pipex->infile_fd != -1)
	{
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd(pipex->argument_1[0], 2);
		ft_putchar_fd('\n', 2);
	}
	if (!pipex->binary_path_2)
	{
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd(pipex->argument_2[0], 2);
		ft_putchar_fd('\n', 2);
	}
}
