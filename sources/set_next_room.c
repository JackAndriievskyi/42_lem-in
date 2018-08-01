/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_next_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:56:46 by yandriie          #+#    #+#             */
/*   Updated: 2018/04/28 14:10:47 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_room_str(char *str, char color)
{
	size_t	i;
	size_t	j;

	if (!str || !*str || *str == RES_CHR || *str == CMD_CHR || *str == LNK_CHR)
		return (ERR_DEFAULT);
	i = 0;
	while (ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (i == 0)
		return (ERR_DEFAULT);
	if (!ft_isspace(str[i]) && color == BLACK)
		return (-1);
	if (!ft_isspace(str[i++]) && color != BLACK)
		return (ERR_DEFAULT);
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (i == j || !ft_isspace(str[i++]))
		return (ERR_DEFAULT);
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (i == j || str[i])
		return (ERR_DEFAULT);
	return (0);
}

static int		add_room(t_node **data, char *label)
{
	t_node	*cur;

	cur = *data;
	while (cur && cur->next)
		if (ft_strcmp(cur->next->label, label))
			cur = cur->next;
		else
			return (ERR_DEFAULT);
	if (!cur)
	{
		if (!(cur = (t_node *)ft_memalloc(sizeof(t_node))))
			return (ERR_MALLOC_FAILED);
		*data = cur;
	}
	else
	{
		if (!ft_strcmp(cur->label, label))
			return (ERR_DEFAULT);
		if (!(cur->next = (t_node *)ft_memalloc(sizeof(t_node))))
			return (ERR_MALLOC_FAILED);
		cur = cur->next;
	}
	if (!(cur->label = ft_strdup(label)))
		return (ERR_MALLOC_FAILED);
	return (0);
}

static int		set_room(t_node **data, char **str, char color)
{
	char	*tmp;
	t_node	*cur;
	int		err;

	if ((err = check_room_str(*str, color)))
		return (err);
	ft_putendl(*str);
	if (!(tmp = ft_strwcut(*str)))
		return (ERR_MALLOC_FAILED);
	free(tmp);
	if ((err = add_room(data, tmp)))
		return (err);
	cur = *data;
	while (cur->next)
		cur = cur->next;
	cur->color = color;
	if (!(tmp = ft_strwcut(*str)))
		return (ERR_MALLOC_FAILED);
	cur->coord.x = ft_atoi(tmp);
	free(tmp);
	if (!(tmp = ft_strwcut(*str)))
		return (ERR_MALLOC_FAILED);
	cur->coord.y = ft_atoi(tmp);
	free(tmp);
	return (0);
}

int				set_next_room(t_node **data, char **str)
{
	if (get_next_line(0, str) < 0)
		return (ERR_MALLOC_FAILED);
	if (*str && **str == CMD_CHR)
	{
		if (!ft_strcmp(*str + 1, START_STR))
		{
			ft_putendl(*str);
			ft_strdel(str);
			if (get_next_line(0, str) < 0)
				return (ERR_MALLOC_FAILED);
			return (set_room(data, str, INPUT));
		}
		if (!ft_strcmp(*str + 1, END_STR))
		{
			ft_putendl(*str);
			ft_strdel(str);
			if (get_next_line(0, str) < 0)
				return (ERR_MALLOC_FAILED);
			return (set_room(data, str, OUTPUT));
		}
		ft_putendl(*str);
		ft_strdel(str);
		return (set_next_room(data, str));
	}
	return (set_room(data, str, BLACK));
}
