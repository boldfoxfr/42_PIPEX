/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:59:19 by agondard          #+#    #+#             */
/*   Updated: 2022/01/20 12:07:29 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_countword(const char *str, char c)
{
	size_t	word;
	size_t	state;

	word = 0;
	state = 1;
	while (*str)
	{
		if (*str == c)
			state = 1;
		else
		{
			if (state == 1)
				word++;
			state = 0;
		}
		str++;
	}
	return (word);
}

size_t	ft_word_len(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**splited;

	i = 0;
	if (s == 0)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!splited)
		return (NULL);
	while (ft_countword(s, c))
	{
		while (*s && *s == c)
			s++;
		splited[i] = (char *)malloc(sizeof(char) * (ft_word_len(s, c) + 1));
		if (!splited[i])
			return (ft_free(splited));
		j = 0;
		while (*s != c && *s)
			splited[i][j++] = *s++;
		splited[i][j] = 0;
		i++;
	}
	splited[i] = 0;
	return (splited);
}
