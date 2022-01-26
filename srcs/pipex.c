/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:09:58 by agondard          #+#    #+#             */
/*   Updated: 2022/01/25 15:56:08 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <errno.h>

void	first_process(t_data *data, char **av, char **envp)
{
	if (data->filein == -1)
		return ;
	dup2(data->filein, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[0]);
	close(data->filein);
	exec_cmd(av[2], envp);
}

void	second_process(t_data *data, char **av, char **envp)
{
	int	wait;

	waitpid(data->pid1, &wait, 0);
	if (data->fileout == -1)
		return ;
	dup2(data->fileout, STDOUT_FILENO);
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[1]);
	exec_cmd(av[3], envp);
}

void	exec_fork(t_data *data, char **av, char **envp)
{
	int	wait;
	int	wait2;

	data->pid1 = fork();
	if (data->pid1 == -1)
		ft_putstr_fd("erreur fork", 2);
	if (data->pid1 == 0)
		first_process(data, av, envp);
	data->pid2 = fork();
	if (data->pid2 == -1)
		ft_putstr_fd("erreur fork", 2);
	if (data->pid2 == 0)
		second_process(data, av, envp);
	close_file(data);
	waitpid(data->pid1, &wait, 0);
	waitpid(data->pid2, &wait2, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data[1];

	if (ac != 5)
		ft_putstr_fd("erreur d'arguments", 2);
	if (open_file(av, data) != 0)
		return (0);
	pipe(data->fd);
	exec_fork(data, av, envp);
	return (0);
}
