/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:44:47 by ybouchma          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:56 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_utilis
{
	char const	*infile;
	char const	*outfile;
	int			infile_fd;
	int			outfile_fd;
	char		**envp;
	char		*binary_path_1;
	char		*binary_path_2;
	char		**argument_1;
	char		**argument_2;
	int			pipe_fd[2];
}	t_utilis;

void	init_t_utilis(t_utilis *pipex, int argc, \
		char const **argv, char **envp);
void	child(t_utilis *pipex);
void	parent(t_utilis *pipex);
void	check_t_utilis(t_utilis *pipex);
void	check_t_utilis_helper(t_utilis *pipex, char *error_msg);
char	*get_binary_path(t_utilis *pipex, char *binary);
void	free_allocated_mem(t_utilis *pipex);
char	*access_path(char **paths, char *binary);

#endif
