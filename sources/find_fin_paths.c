/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fin_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:19:09 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/20 10:25:39 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		get_max_ways(t_node *data)
{
	int		max;
	int		tmp;
	int		f;
	t_link	*cur;

	max = 0;
	f = 0;
	while (data && f != 2)
	{
		if (data->color == INPUT || data->color == OUTPUT)
		{
			tmp = 0;
			cur = data->link;
			while (cur)
			{
				check(data, cur->link, &tmp);
				cur = cur->next;
			}
			if (!max || max > tmp)
				max = tmp;
			f++;
		}
		data = data->next;
	}
	return (max);
}

static int		all_is_ok(t_fin *this, t_path *path)
{
	t_trace		*cmp1;
	t_trace		*cmp2;

	this = this->next;
	while (this)
	{
		cmp1 = this->path->trace;
		while (cmp1)
		{
			cmp2 = path->trace;
			while (cmp2)
			{
				if (cmp1->node == cmp2->node && cmp1->node->color != OUTPUT)
					return (0);
				cmp2 = cmp2->next;
			}
			cmp1 = cmp1->next;
		}
		this = this->next;
	}
	return (1);
}

static int		get_this_fin(t_fin *t, t_path *p, int *ma, t_fin **s)
{
	t_fin	*tmp2;
	int		ret;

	if (all_is_ok(t, p))
	{
		tmp2 = find_last(t);
		if (!(tmp2->next = (t_fin *)ft_memalloc(sizeof(t_fin))))
			return (ERR_MALLOC);
		tmp2->next->path = p;
		if (!ma[0])
			return (try_swap(t, s, ma));
		while (p->next)
		{
			ma[0]--;
			if ((ret = get_this_fin(t, p->next, ma, s)) > 0)
				return (ERR_MALLOC);
			else if (!ret)
				del_last_path(t);
			ma[0]++;
			p = p->next;
		}
	}
	return (-1);
}

static int		get_fin(t_fin **res, t_path *paths, int *ma)
{
	t_fin	*tmp;
	t_fin	*tmp2;
	t_path	*cur;

	if (!(tmp = (t_fin *)ft_memalloc(sizeof(t_fin))))
		return (ERR_MALLOC);
	while (ma[0]--)
	{
		cur = paths;
		while (cur)
		{
			tmp2 = NULL;
			if (get_this_fin(tmp, cur, ma, &tmp2) > 0)
				return (clear2(tmp, tmp2));
			if (!*res ||
				(tmp2 && tmp2->rounds <= (*res)->rounds && tmp2->rounds))
				copy_this(res, tmp2);
			while (tmp2)
				tmp2 = clear1(tmp2);
			clear3(tmp);
			cur = cur->next;
		}
	}
	free(tmp);
	return (0);
}

int				find_fin_paths(t_node *data, t_path *paths, int ants)
{
	t_fin	*res;
	int		maxants[2];

	res = NULL;
	maxants[0] = get_max_ways(data);
	maxants[1] = ants;
	if (get_fin(&res, paths, maxants))
	{
		while (res)
			res = clear1(res);
		return (ERR_MALLOC);
	}
	maxants[0] = get_max_ways(data);
	if (!res)
	{
		while (res)
			res = clear1(res);
		return (ERR_INPUT);
	}
	print_ants(res, maxants[1], maxants[0]);
	while (res)
		res = clear1(res);
	return (0);
}
