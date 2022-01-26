/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 08:38:55 by agondard          #+#    #+#             */
/*   Updated: 2022/01/20 12:07:39 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[a] != '\0')
	{
		b = 0;
		while (to_find[b] == str[a + b] && (a + b) < len)
		{
			if (to_find[b + 1] == '\0')
				return ((char *)str + a);
			b++;
		}
		a++;
	}
	return (0);
}
