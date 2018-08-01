/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:51:06 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/18 11:10:10 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *ptr, size_t size)
{
	unsigned char	*res;
	register size_t	n;

	if (!ptr)
		return ((char *)ft_memalloc(sizeof(unsigned char) * size));
	n = ft_strlen(ptr);
	if (!(res = (unsigned char *)ft_memalloc(sizeof(unsigned char) * size)))
		return (NULL);
	if (size >= n)
		ft_memmove(res, ptr, n);
	else
	{
		ft_memmove(res, ptr, size);
		res[size] = '\0';
	}
	free(ptr);
	return ((char *)res);
}
