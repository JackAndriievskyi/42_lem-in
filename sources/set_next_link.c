/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_next_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:41:18 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/10 14:53:34 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_link_str(char *str)
{
	size_t	i;
	size_t	j;

	if (*str == LNK_CHR || *str == RES_CHR)
		return (ERR_DEFAULT);
	i = 0;
	while (ft_isprint(str[i]) && !ft_isspace(str[i]) && str[i] != LNK_CHR)
		i++;
	if (!i || str[i++] != LNK_CHR || str[i] == RES_CHR || str[i] == LNK_CHR)
		return (ERR_DEFAULT);
	j = 0;
	while (ft_isprint(str[i + j]) && !ft_isspace(str[i + j])
		&& str[i] != LNK_CHR)
		j++;
	if (str[i + j] || !j)
		return (ERR_DEFAULT);
	return (0);
}

static int		add_link(t_node *tmp1, t_node *tmp2)
{
	t_link	*cur;

	cur = tmp1->link;
	while (cur && cur->next)
		cur = cur->next;
	if (!cur)
	{
		if (!(cur = (t_link *)ft_memalloc(sizeof(t_link))))
			return (ERR_MALLOC_FAILED);
		tmp1->link = cur;
	}
	else
	{
		if (!(cur->next = (t_link *)ft_memalloc(sizeof(t_link))))
			return (ERR_MALLOC_FAILED);
		cur = cur->next;
	}
	cur->link = tmp2;
	return (0);
}

static int		set_link(t_node *data, char *str)
{
	t_node	*tmp1;
	t_node	*tmp2;
	size_t	i;

	tmp1 = NULL;
	tmp2 = NULL;
	i = 0;
	while (str[i] != LNK_CHR)
		i++;
	while (data && (!tmp1 || !tmp2))
	{
		if (!ft_strncmp(data->label, str, i))
			tmp1 = data;
		if (!ft_strcmp(data->label, str + i + 1))
			tmp2 = data;
		data = data->next;
	}
	if (!tmp1 || !tmp2)
		return (ERR_DEFAULT);
	if (add_link(tmp1, tmp2))
		return (ERR_MALLOC_FAILED);
	if (add_link(tmp2, tmp1))
		return (ERR_MALLOC_FAILED);
	return (0);
}

int				set_next_link(t_node *data, char **str)
{
	int		check;

	if (!*str)
		if (get_next_line(0, str) < 0)
			return (ERR_MALLOC_FAILED);
	if (*str && **str == CMD_CHR)
	{
		ft_putendl(*str);
		ft_strdel(str);
		return (set_next_link(data, str));
	}
	if (!*str || !**str)
		return (-1);
	if ((check = check_link_str(*str)) > 0)
		return (ERR_DEFAULT);
	else if (check < 0)
	{
		ft_putendl(*str);
		return (check * (-1) - 1);
	}
	ft_putendl(*str);
	return (set_link(data, *str));
}
