/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:00:57 by yandriie          #+#    #+#             */
/*   Updated: 2018/04/18 12:23:51 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		set_ants(int *ants, char **str)
{
	size_t	i;

	if (get_next_line(0, str) < 0)
		return (ERR_MALLOC_FAILED);
	i = 0;
	if (!*str || !**str)
		return (ERR_DEFAULT);
	while (ft_isdigit((*str)[i]))
		i++;
	if ((*str)[i])
		return (ERR_DEFAULT);
	ft_putendl(*str);
	*ants = ft_atoi(*str);
	if (ants <= 0)
		return (ERR_DEFAULT);
	ft_strdel(str);
	return (0);
}
