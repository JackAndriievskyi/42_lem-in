/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:51:05 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/18 11:32:19 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;
	char	*res;

	ch = (char)c;
	i = -1;
	res = NULL;
	if (s)
	{
		while (s[++i] != '\0')
			if (s[i] == ch)
			{
				res = (char *)&(s[i]);
				return (res);
			}
		if (s[i] == ch)
			res = (char *)&(s[i]);
	}
	return (res);
}
