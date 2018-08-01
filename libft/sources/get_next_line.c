/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:52:00 by yandriie          #+#    #+#             */
/*   Updated: 2018/06/20 10:26:25 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	formres(char **line, char **save)
{
	register size_t	i;
	register size_t	j;
	char			*tmp;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	*line = (char *)ft_memmove(*line, *save, i);
	if ((*save)[i] == '\0')
	{
		ft_bzero(*save, i);
		free(*save);
		*save = NULL;
		return (1);
	}
	j = 0;
	while ((*save)[i + 1 + j] != '\0')
		j++;
	tmp = *save;
	*save = ft_strsub(*save, i + 1, j);
	free(tmp);
	return (1);
}

static int	readthis(char **line, char **save, const int fd, size_t i)
{
	char	buf[BUFF_SIZE];
	size_t	size;
	int		ret;
	int		f;

	size = i;
	f = 0;
	while (!ft_strchr(*save, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		f++;
		i = size;
		size += ret;
		if (!((*save) = ft_strrealloc(*save, size + 1)))
			return (-1);
		ft_memmove((*save) + i, buf, ret);
	}
	if (ret == -1 || (f == 0 && i == 0))
	{
		*line = *save;
		return (ret);
	}
	return (formres(line, save));
}

int			get_next_line(const int fd, char **line)
{
	static char		*save;
	register size_t	i;

	if (fd < 0 || !line)
		return (-1);
	i = 0;
	if (save)
		while (save[i] != '\n' && save[i] != '\0')
			i++;
	if (!save || !save[i])
		return (readthis(line, &save, fd, i));
	return (formres(line, &save));
}
