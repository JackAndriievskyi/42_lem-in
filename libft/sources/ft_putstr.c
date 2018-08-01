/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:38:35 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/18 10:17:20 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	register size_t	size;

	if (s == NULL)
		return ;
	size = 0;
	while (s[size] != '\0')
		size++;
	write(1, s, size);
}
