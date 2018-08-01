/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:09:04 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/10 14:59:24 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_fin		*clear1(t_fin *this)
{
	t_fin	*ret;

	ret = this->next;
	free(this);
	return (ret);
}

int			clear2(t_fin *this1, t_fin *this2)
{
	t_fin	*tmp;

	while (this1)
	{
		tmp = this1->next;
		free(this1);
		this1 = tmp;
	}
	while (this2)
	{
		tmp = this2->next;
		free(this2);
		this2 = tmp;
	}
	return (ERR_MALLOC);
}

t_fin		*find_last(t_fin *t)
{
	while (t && t->next)
		t = t->next;
	return (t);
}

int			copy_this(t_fin **s, t_fin *t)
{
	t_fin	*tmp;

	if (!t)
		return (0);
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	if (!((*s) = (t_fin *)ft_memalloc(sizeof(t_fin))))
		return (ERR_MALLOC);
	(*s)->rounds = t->rounds;
	tmp = *s;
	while (t->next)
	{
		if (!(tmp->next = (t_fin *)ft_memalloc(sizeof(t_fin))))
			return (ERR_MALLOC);
		tmp = tmp->next;
		t = t->next;
		tmp->path = t->path;
	}
	return (0);
}

int			try_swap(t_fin *t, t_fin **s, int *ma)
{
	t->rounds = count_rounds(t, ma[1]);
	if (!(*s) || (t->rounds < (*s)->rounds && t->rounds && (*s)->rounds))
		if (copy_this(s, t))
			return (ERR_MALLOC);
	return (0);
}
