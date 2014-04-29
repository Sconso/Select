/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skinsinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 23:29:16 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 23:34:32 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <ft_fc_mem.h>
#include <termcap.h>
#include <unistd.h>

static void		ft_printskinlist2(t_control *list, char **modetab, t_cursor cur)
{
		cur.x = (list->width / 2) - 11;
		cur.y = 0;
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|        SKINS        |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|                     |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|     1 = Default     |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|   2 = Hello Kitty   |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|    3 = Dark Goth    |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|     4 = Jamaica     |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|      5 = BSOD       |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		tputs(modetab[UNDERLINED], 1, ft_outc);
		ft_putshell("|                     |");
		tputs(modetab[CLEAN], 1, ft_outc);
		list->state = 1;

}

static void		ft_printskinlist(t_control *list, char **modetab)
{
	t_cursor	cur;

	if (list->state == 0)
		ft_printskinlist2(list, modetab, cur);
	else
		ft_clear(modetab, list, 1);
}

static int		ft_changeskin(char **modetab, char *buf)
{
	if (buf[0] == '1')
		ft_default(modetab);
	else if (buf[0] == '2')
		ft_hellokitty(modetab);
	else if (buf[0] == '3')
		ft_darkgoth(modetab);
	else if (buf[0] == '4')
		ft_jamaica(modetab);
	else if (buf[0] == '5')
		ft_bsod(modetab);
	else if (ESC)
		;
	else if (buf[0] == 'c')
		;
	else
		return (0);
	ft_clear(modetab, 0, 1);
	return (-1);
}

void			ft_selectskin(t_control *list, char **modetab)
{
	char		buf[5];
	int			ret;

	ft_printskinlist(list, modetab);
	while ((ret = read(0, buf, 4)))
	{
		buf[ret] = 0;
		if (ft_changeskin(modetab, buf) == -1)
			break ;
		ft_bzero(buf, 5);
	}
}
