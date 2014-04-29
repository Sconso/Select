/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afflist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:13:26 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 21:17:52 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <termcap.h>
#include <stdlib.h>

static void		ft_calccurx(t_cursor *c, int *col, t_control *lst, t_cursor wh)
{
	++(*col);
	c->x = lst->width / wh.x;
	c->x = (*col * c->x) - (c->x / 2);
}

static void		ft_move_cursor(t_args *tmp, int x, int y, char **modetab)
{
	tmp->x = x - ft_floor((double)tmp->size / 2);
	tmp->y = y;
	tputs(tgoto(modetab[CM], tmp->x, tmp->y), 1, ft_outc);
}

static void		ft_put_elem(t_control *list, char **modetab, t_args *tmp)
{
	if (list->active == tmp)
		tputs(modetab[UNDERLINED], 1, ft_outc);
	if (tmp->selected == 1)
		tputs(modetab[REVERSE_VIDEO], 1, ft_outc);
	ft_putshell(tmp->name);
	tputs(modetab[CLEAN], 1, ft_outc);

}

static void		ft_affelem(t_control *lst, char **mod, t_cursor c, t_cursor wh)
{
	int		j;
	int		col;
	int		size;
	char	*str;
	t_args	*tmp;

	str = ft_strnewset(lst->width, ' ');
	j = 0;
	col = 0;
	size = lst->size;
	tmp = lst->first;
	while (size--)
	{
		ft_putshell(mod[LISTC]);
		if (!j)
			ft_calccurx(&c, &col, lst, wh);
		tputs(tgoto(mod[CM], 0, c.y + j + 1), 1, ft_outc);
		if (col == 1)
			ft_putshell(str);
		ft_move_cursor(tmp, c.x, c.y + j + 1, mod);
		j = (j + 1 < (int)wh.y ? j + 1 : 0);
		ft_put_elem(lst, mod, tmp);
		tmp = tmp->next;
	}
}

void			ft_afflist(t_control *list, char **mode, int lines, int colsnb)
{
	char		*str;
	t_cursor	cur;
	t_cursor	infos;

	infos.x = colsnb;
	infos.y = lines;
	cur.y = list->height - (list->height / 2);
	cur.y -= (lines / 2) - 2;
	str = ft_strnewset(list->width, '=');
	ft_afflogo(list->width, mode, list->width >= 46);
	tputs(tgoto(mode[CM], 0, cur.y), 1, ft_outc);
	ft_putshell(NONEC);
	ft_putshell(mode[LINEC]);
	ft_putshell(str);
	ft_affelem(list, mode, cur, infos);
	tputs(tgoto(mode[CM], 0, cur.y + lines + 1), 1, ft_outc);
	ft_putshell(mode[LINEC]);
	ft_putshell(str);
	ft_putshell(NONEC);
	free(str);
}
