/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:17:38 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/10 14:56:33 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			swap_rounds(t_path *cur, t_path **last)
{
	t_path	*tmp1;
	t_path	*tmp2;

	while (cur->next->next != *last)
	{
		if (cur->next->size > cur->next->next->size)
		{
			tmp1 = cur->next;
			tmp2 = cur->next->next->next;
			cur->next = cur->next->next;
			cur->next->next = tmp1;
			cur->next->next->next = tmp2;
		}
		cur = cur->next;
	}
	*last = cur->next;
}

void				sort_paths(t_path **paths)
{
	t_path	*last;
	t_path	*head;

	if (!(*paths) || !(*paths)->next)
		return ;
	last = NULL;
	head = *paths;
	while (last != head && head->next)
	{
		if (head->size > head->next->size)
		{
			*paths = head->next;
			head->next = head->next->next;
			(*paths)->next = head;
			head = *paths;
		}
		if (head->next->next != last)
			swap_rounds(head, &last);
		else
			last = head;
	}
}
