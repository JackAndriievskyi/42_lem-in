/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:09:47 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/18 10:14:32 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	register size_t	size;

	size = 0;
	if (s == NULL)
		return ;
	while (s[size] != '\0')
		size++;
	write(1, s, size);
	write(1, "\n", 1);
}
