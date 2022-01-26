/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:28:35 by agondard          #+#    #+#             */
/*   Updated: 2022/01/25 16:33:02 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*pathname_and_cmd(char **envp, char **cmd)
{
	char	**path;
	char	*first_part;
	char	*final_path;
	int		i;

	i = 0;
	if (envp[i] == NULL)
		ft_putstr_fd("erreur de PATH", 2);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		first_part = ft_strjoin(path[i], "/");
		final_path = ft_strjoin(first_part, cmd[0]);
		free (first_part);
		first_part = NULL;
		if (access(final_path, F_OK) == 0)
			return (final_path);
		i++;
		free (final_path);
	}
	ft_free(path);
	return (0);
}

void	exec_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = pathname_and_cmd(envp, cmd);
	if (!path)
	{
		ft_free(cmd);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free(cmd);
		free(path);
		exit(127);
	}
}

int	open_file(char **av, t_data *data)
{
	data->fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->filein = open(av[1], O_RDONLY);
	if (data->fileout == -1)
	{
		close (data->filein);
		return (1);
	}
	if (data->filein == -1)
	{
		close(data->fileout);
		return (1);
	}
	return (0);
}

void	close_file(t_data *data)
{
	close(data->fd[1]);
	close(data->filein);
	close(data->fd[0]);
	close(data->fileout);
}
