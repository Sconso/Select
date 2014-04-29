/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:56:03 by sconso            #+#    #+#             */
/*   Updated: 2014/01/08 19:18:04 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <ft_fc_str.h>
#include <ft_fc_print.h>
#include <stdlib.h>

t_control		*ft_newlist(void)
{
	t_control	*tmp;

	tmp = (t_control *)malloc(sizeof(*tmp));
	if (!tmp)
		ft_exit("Error\n");
	tmp->size = 0;
	tmp->maxcol = 0;
	tmp->width = 0;
	tmp->height = 0;
	tmp->usable = 1;
	tmp->state = 0;
	tmp->first = NULL;
	tmp->last = NULL;
	return (tmp);
}

static void		ft_pushlast_insert(t_control *list, t_args *node)
{
	if (list->last == NULL)
	{
		list->first = node;
		list->last = node;
		node->prev = node;
		list->active = node;
		list->maxcol = node;
	}
	else
	{
		list->maxcol = (node->size > list->maxcol->size ? node : list->maxcol);
		list->last->next = node;
		list->first->prev = node;
		node->prev = list->last;
		list->last = node;
	}
	node->next = list->first;
}

t_args			*ft_pushlast(t_control *list, char *name)
{
	t_args	*node;

	node = (t_args *)malloc(sizeof(*node));
	if (list == NULL || !node)
		ft_exit("Error\n");
	node->name = ft_strdup(name);
	node->selected = 0;
	node->size = ft_strlen(name);
	ft_pushlast_insert(list, node);
	list->size += 1;
	return (node);
}

static void		ft_calc_max_cols(t_control *list)
{
	int			i;
	t_args		*node;

	i = -1;
	list->maxcol = list->first;
	node = list->first;
	while (++i < list->size)
	{
		if (node->size > list->maxcol->size)
			list->maxcol = node;
		node = node->next;
	}
}

void			ft_delete_node(t_control *list, t_args *node)
{
	if (!node || !list)
		return ;
	if (node == list->last)
		list->active = (list->size == 1 ? 0 : node->prev);
	else
		list->active = (list->size == 1 ? 0 : node->next);
	if (node == list->first)
		list->first = (list->size == 1 ? 0 : node->next);
	if (node == list->last)
		list->last = (list->size == 1 ? 0 : node->prev);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	list->size--;
	if (node == list->maxcol && list->first)
		ft_calc_max_cols(list);
	free(node->name);
	free(node);
	node = 0;
}
