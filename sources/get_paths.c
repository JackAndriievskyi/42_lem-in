/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:32:33 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/10 14:15:03 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		free_trace(t_trace *trace)
{
	t_trace *tmp;

	while (trace->next)
	{
		tmp = trace->next;
		free(trace);
		trace = tmp;
	}
	return (ERR_MALLOC);
}

static void		del_last_trace(t_trace *trace)
{
	while (trace->next->next)
		trace = trace->next;
	free(trace->next);
	trace->next = NULL;
}

static int		add_this(t_path *cur, t_trace *trace)
{
	t_trace *tmp;

	if (!(cur->trace = (t_trace *)ft_memalloc(sizeof(t_trace))))
		return (free_trace(trace));
	trace = trace->next;
	cur->trace->node = trace->node;
	cur->size++;
	tmp = cur->trace;
	while ((trace = trace->next))
	{
		cur->size++;
		if (!(tmp->next = (t_trace *)ft_memalloc(sizeof(t_trace))))
			return (free_trace(trace));
		tmp = tmp->next;
		tmp->node = trace->node;
	}
	return (0);
}

static int		add_path(t_trace *trace, t_path **paths)
{
	t_path	*cur;

	if (!(*paths))
	{
		if (!((*paths) = (t_path *)ft_memalloc(sizeof(t_path))))
			return (free_trace(trace));
		cur = *paths;
	}
	else
	{
		cur = *paths;
		while (cur && cur->next)
			cur = cur->next;
		if (!(cur->next = (t_path *)ft_memalloc(sizeof(t_path))))
			return (free_trace(trace));
		cur = cur->next;
	}
	return (add_this(cur, trace));
}

int				get_paths(t_trace *trace, t_path **paths, t_node *cur)
{
	t_trace	*tmp;
	t_link	*links;

	tmp = trace;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = (t_trace *)ft_memalloc(sizeof(t_trace))))
		return (free_trace(trace));
	tmp->next->node = cur;
	if (cur->color == INPUT || cur->color == RED)
		return (0);
	if (cur->color == OUTPUT)
		return (add_path(trace, paths));
	cur->color = RED;
	links = cur->link;
	while (links)
	{
		if (get_paths(trace, paths, links->link) == ERR_MALLOC)
			return (free_trace(trace));
		del_last_trace(trace);
		links = links->next;
	}
	cur->color = BLACK;
	return (0);
}
