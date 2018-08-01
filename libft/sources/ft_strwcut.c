/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:14:27 by yandriie          #+#    #+#             */
/*   Updated: 2018/04/12 16:26:49 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strwcut(char *str)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	j = 0;
	while (str[i + j] && !ft_isspace(str[i + j]))
		j++;
	if (!(res = (char *)ft_memalloc(sizeof(char) * (j + 1))))
		return (NULL);
	k = 0;
	while (k < j)
	{
		res[k] = str[i + k];
		str[i + k] = ' ';
		k++;
	}
	res[k] = 0;
	return (res);
}
