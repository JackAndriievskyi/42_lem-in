/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:57:13 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/12 10:56:52 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			fin_print(t_node *targ)
{
	if (targ->n_ant > 0)
	{
		ft_putchar(RES_CHR);
		ft_putnbr(targ->n_ant);
		ft_putchar(LNK_CHR);
		ft_putstr(targ->label);
		ft_putchar(' ');
	}
}

static void			push_ants(t_trace *cur, int name)
{
	if (!cur)
		return ;
	push_ants(cur->next, cur->node->n_ant);
	cur->node->n_ant = name;
	fin_print(cur->node);
}

void				print_ants(t_fin *paths, int ants, int max)
{
	t_fin	*cur;
	int		i;
	int		j;
	int		border;

	i = 0;
	border = get_border(paths, max);
	while (paths->rounds--)
	{
		if (ants - i < border)
			border = get_border(paths, --max);
		cur = paths->next;
		j = 0;
		while (cur)
		{
			if (j < max && ants - i > 0)
				push_ants(cur->path->trace, ++i);
			else
				push_ants(cur->path->trace, 0);
			j++;
			cur = cur->next;
		}
		ft_putendl("");
	}
}
