/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:15:09 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 21:21:36 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <termcap.h>

void	ft_changeactive(t_control *list, t_args *new, char **modetab)
{
	t_args		*old;

	old = list->active;
	ft_putshell(modetab[LISTC]);
	tputs(tgoto(modetab[CM], old->x, old->y), 1, ft_outc);
	if (old->selected)
		tputs(modetab[REVERSE_VIDEO], 1, ft_outc);
	ft_putshell(old->name);
	tputs(modetab[CLEAN], 1, ft_outc);
	tputs(tgoto(modetab[CM], new->x, new->y), 1, ft_outc);
	ft_putshell(modetab[LISTC]);
	tputs(modetab[UNDERLINED], 1, ft_outc);
	if (new->selected)
		tputs(modetab[REVERSE_VIDEO], 1, ft_outc);
	ft_putshell(new->name);
	tputs(modetab[CLEAN], 1, ft_outc);
	list->active = new;
}


void	ft_changecol(t_control *list, char mode, char **modetab)
{
	t_args		*node;

	node = list->active;
	node = (mode != 0 ? node->next : node->prev);
	while (node->y != list->active->y)
		node = (mode != 0 ? node->next : node->prev);
	ft_changeactive(list, node, modetab);
}
