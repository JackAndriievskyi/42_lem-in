/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:50:51 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/10 15:07:47 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_coord(t_node *data)
{
	t_node	*tmp;

	while (data)
	{
		tmp = data->next;
		while (tmp)
		{
			if (data->coord.x == tmp->coord.x &&
				data->coord.y == tmp->coord.y)
				return (ERR_DEFAULT);
			tmp = tmp->next;
		}
		data = data->next;
	}
	return (0);
}

static int		check_ioroom(t_node *data)
{
	int		in;
	int		out;

	in = 1;
	out = 1;
	while (data && in > -1 && out > -1)
	{
		if (data->color == INPUT)
		{
			in--;
			if (!data->link)
				return (ERR_INPUT);
		}
		if (data->color == OUTPUT)
		{
			out--;
			if (!data->link)
				return (ERR_INPUT);
		}
		data = data->next;
	}
	if (!in && !out)
		return (0);
	return (ERR_INPUT);
}

int				check_data(t_node *data)
{
	int		err;

	if ((err = check_ioroom(data)))
		return (err);
	if ((err = check_coord(data)))
		return (err);
	return (0);
}
