/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:43:01 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/20 10:27:42 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				get_border(t_fin *t, int max)
{
	int		border;
	int		cur;

	border = 0;
	cur = 1;
	t = t->next;
	if (max == 1)
		return (0);
	border -= (t->path->size - 1);
	t = t->next;
	max--;
	while (cur < max && t)
	{
		border -= (t->path->size * cur);
		t = t->next;
		cur++;
	}
	if (t)
		border += (t->path->size * cur);
	return (border);
}

int				count_rounds(t_fin *t, int ants)
{
	int		res;
	int		max;
	int		border;
	t_fin	*tmp;

	res = 0;
	max = 0;
	tmp = t;
	while ((tmp = tmp->next))
		max++;
	border = get_border(t, max);
	while (ants > 0)
	{
		if (border > ants && max != 1)
			border = get_border(t, max--);
		else
		{
			ants -= max;
			res++;
		}
	}
	while (max--)
		t = t->next;
	return (res + t->path->size - 1);
}

int				del_last_path(t_fin *t)
{
	while (t->next && t->next->next)
		t = t->next;
	free(t->next);
	t->next = NULL;
	return (0);
}

void			clear3(t_fin *tmp)
{
	t_fin	*save;

	save = tmp;
	tmp = tmp->next;
	while (tmp)
		tmp = clear1(tmp);
	ft_bzero(save, sizeof(t_fin));
}

void			check(t_node *cmp1, t_node *cmp2, int *cnt)
{
	if (cmp1->color == INPUT && cmp2->color == INPUT)
		return ;
	if (cmp1->color == OUTPUT && cmp2->color == OUTPUT)
		return ;
	(*cnt)++;
}
