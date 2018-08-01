/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 10:22:06 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/18 11:22:58 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t p_size, size_t n_size)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)ft_memalloc(sizeof(unsigned char) * n_size)))
		return (NULL);
	if (n_size >= p_size)
		ft_memmove(res, ptr, p_size);
	else
		ft_memmove(res, ptr, n_size);
	if (ptr)
		free(ptr);
	return ((void *)res);
}
