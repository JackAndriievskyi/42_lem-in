/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:46:26 by yandriie          #+#    #+#             */
/*   Updated: 2018/08/01 09:19:02 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

# define ERR_DEFAULT 1
# define ERR_INPUT 2
# define ERR_MALLOC_FAILED 3
# define ERR_MALLOC ERR_MALLOC_FAILED
# define CMD_CHR '#'
# define LNK_CHR '-'
# define RES_CHR 'L'
# define START_STR "#start"
# define END_STR "#end"

# define BLACK 0
# define GREEN 'g'
# define ORANGE 'o'
# define RED 'r'
# define INPUT GREEN
# define OUTPUT ORANGE

typedef struct s_link	t_link;
typedef struct s_coord	t_coord;
typedef struct s_node	t_node;
typedef struct s_trace	t_trace;
typedef struct s_path	t_path;
typedef struct s_fin	t_fin;

struct					s_link
{
	t_node				*link;
	t_link				*next;
};

struct					s_coord
{
	int					x;
	int					y;
};

struct					s_node
{
	char				*label;
	char				color;
	int					n_ant;
	t_link				*link;
	t_node				*next;
	t_coord				coord;
};

struct					s_trace
{
	t_node				*node;
	t_trace				*next;
};

struct					s_path
{
	t_trace				*trace;
	int					size;
	t_path				*next;
};

struct					s_fin
{
	t_path				*path;
	int					rounds;
	t_fin				*next;
};

/*
**						Parse'n'Check
*/

int						set_ants(int *ants, char **str);
int						set_next_room(t_node **data, char **str);
int						set_next_link(t_node *data, char **str);
int						check_data(t_node *data);

/*
**						Algorithm
*/

int						get_paths(t_trace *trace, t_path **paths, t_node *cur);
void					sort_paths(t_path **paths);
int						find_fin_paths(t_node *data, t_path *paths, int ants);
void					print_ants(t_fin *paths, int ants, int max);

/*
**						Utilities
*/

int						try_swap(t_fin *t, t_fin **s, int *ma);
t_fin					*find_last(t_fin *t);
t_fin					*clear1(t_fin *this);
int						clear2(t_fin *this1, t_fin *this2);
int						copy_this(t_fin **s, t_fin *t);
int						get_border(t_fin *t, int max);
int						count_rounds(t_fin *t, int ants);
int						del_last_path(t_fin *t);
void					clear3(t_fin *tmp);
void					check(t_node *cmp1, t_node *cmp2, int *cnt);

#endif
