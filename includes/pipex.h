/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:27:46 by agondard          #+#    #+#             */
/*   Updated: 2022/01/25 16:24:14 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
// process FORK & WAIT
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_data {
	int	filein;
	int	fileout;
	int	fd[2];
	int	pid1;
	int	pid2;
}	t_data;

// fonctions de ma libft
char	**ft_free(char **str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
// pipex mandatory
char	*pathname_and_cmd(char **envp, char **cmd);
void	exec_cmd(char *av, char **envp);
void	exec_fork(t_data *data, char **av, char **env);
int		open_file(char **av, t_data *data);
void	first_process(t_data *data, char **av, char **envp);
void	second_process(t_data *data, char **av, char **envp);
void	close_file(t_data *data);

#endif
