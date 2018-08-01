/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:56:03 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/12 11:39:35 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		data_free(t_node *data, char *str)
{
	t_node	*tmp;
	t_link	*tmp_l;

	if (str)
		free(str);
	while (data)
	{
		while (data->link)
		{
			tmp_l = data->link->next;
			free(data->link);
			data->link = tmp_l;
		}
		if (data->label)
			free(data->label);
		tmp = data->next;
		free(data);
		data = tmp;
	}
}

static int		err_handle(int err, t_node *data, char *str)
{
	if (err == ERR_INPUT)
		ft_putendl("ERROR");
	if (err == ERR_MALLOC_FAILED)
		ft_putendl("\tmalloc failed... ");
	if (err == ERR_DEFAULT)
		ft_putendl("\twrong data or input format... ");
	data_free(data, str);
	return (1);
}

static int		paths_free(t_trace *trace, t_path *paths, int err)
{
	t_path	*tmp1;
	t_trace	*tmp2;

	while (paths)
	{
		while (paths->trace)
		{
			tmp2 = paths->trace->next;
			free(paths->trace);
			paths->trace = tmp2;
		}
		tmp1 = paths->next;
		free(paths);
		paths = tmp1;
	}
	while (trace)
	{
		tmp2 = trace->next;
		free(trace);
		trace = tmp2;
	}
	return (err);
}

static int		lemin_manip(t_node *data, int ants)
{
	t_path	*paths;
	t_node	*start;
	t_link	*link;
	t_trace	*trace;
	int		err;

	paths = NULL;
	start = data;
	while (start && start->color != INPUT)
		start = start->next;
	link = start->link;
	if (!(trace = (t_trace *)ft_memalloc(sizeof(t_trace))))
		return (ERR_MALLOC);
	while (link)
	{
		if ((err = get_paths(trace, &paths, link->link)))
			return (paths_free(trace, paths, err));
		link = link->next;
		free(trace->next);
		trace->next = NULL;
	}
	sort_paths(&paths);
	if ((err = find_fin_paths(data, paths, ants)))
		return (paths_free(trace, paths, err));
	return (paths_free(trace, paths, 0));
}

int				main(void)
{
	int		ants;
	t_node	*data;
	int		err;
	char	*str;

	data = NULL;
	str = NULL;
	if ((err = set_ants(&ants, &str)))
		return (err_handle(err, data, str));
	while ((err = set_next_room(&data, &str)) == 0)
		ft_strdel(&str);
	if (err > 0)
		return (err_handle(err, data, str));
	while ((err = set_next_link(data, &str)) == 0)
		ft_strdel(&str);
	if (err > 0)
		return (err_handle(err, data, str));
	if ((err = check_data(data)))
		return (err_handle(err, data, str));
	if ((err = lemin_manip(data, ants)))
		return (err_handle(err, data, str));
	data_free(data, str);
	return (0);
}
