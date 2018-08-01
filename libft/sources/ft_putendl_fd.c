/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:03:26 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/18 10:14:22 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	register size_t	size;

	if (s == NULL)
		return ;
	size = 0;
	while (s[size] != '\0')
		size++;
	write(fd, s, size);
	write(fd, "\n", 1);
}
