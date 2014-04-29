/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:15:33 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 21:41:10 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		ft_arrows(char *buf, t_control *list, char **modetab)
{
	if (buf[2] == 65)
		ft_changeactive(list, list->active->prev, modetab);
	else if (buf[2] == 66)
		ft_changeactive(list, list->active->next, modetab);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		ft_changecol(list, 1, modetab);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
		ft_changecol(list, 0, modetab);
}

void			ft_keys(char *buf, t_control *list, char **modetab)
{
	if (ARROW)
		ft_arrows(buf, list, modetab);
	else if (SPACE)
		ft_addselected(list, modetab);
	else if (BACKSPACE || SUPPR)
	{
		ft_delete_node(list, list->active);
		ft_clear(modetab, list, 1);
	}
	else if (ENTER)
		ft_quit(modetab, list, 0, ft_calcret(list));
	else if (MINUS)
		ft_multiselect(list, 0, modetab);
	else if (PLUS)
		ft_multiselect(list, 1, modetab);
	else if (SLASH)
		ft_search(list, modetab);
	else if (QUESTIONMARK)
		ft_printhelp(list, modetab);
	else if (buf[0] == 'c' && !buf[1])
		ft_selectskin(list, modetab);
}
