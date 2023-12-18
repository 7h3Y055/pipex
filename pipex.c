/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:41:50 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/18 09:42:35 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char const **argv, char **envp)
{
	int			pid;
	int			status;
	t_utilis	pipex;

	if (argc != 5)
	{
		ft_printf("usage:\n%s infile cmd1 cmd2 outfile\n", argv[0]);
		return (1);
	}
	init_t_utilis(&pipex, argc, argv, envp);
	check_t_utilis(&pipex);
	pid = fork();
	if (pid == -1)
		ft_putendl_fd("Fork: Resource unavailable", 2);
	else if (pid == 0)
		child(&pipex);
	else
		parent(&pipex);
	waitpid(pid, &status, 0);
	free_allocated_mem(&pipex);
	return (0);
}
