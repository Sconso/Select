/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printthings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:14:25 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 21:16:35 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <termcap.h>

void	ft_afflogo(int width, char **modetab, char mode)
{
	int		i;

	i = 0;
	ft_putshell(modetab[BGC]);
	ft_putshell(modetab[LOGOC]);
	if (!mode)
	{
		tputs(tgoto(modetab[CM], width / 2 - 4, ++i), 1, ft_outc);
		ft_putshell("Selector");
		return ;
	}
	tputs(tgoto(modetab[CM], width / 2 - 23, ++i), 1, ft_outc);
	ft_putshell(" _____        _              _                ");
	tputs(tgoto(modetab[CM], width / 2 - 23, ++i), 1, ft_outc);
	ft_putshell("/  ___|      | |            | |               ");
	tputs(tgoto(modetab[CM], width / 2 - 23, ++i), 1, ft_outc);
	ft_putshell("\\ `--.   ___ | |  ___   ___ | |_   ___   _ __ ");
	tputs(tgoto(modetab[CM], width / 2 - 23, ++i), 1, ft_outc);
	ft_putshell(" `--. \\ / _ \\| | / _ \\ / __|| __| / _ \\ | '__|");
	tputs(tgoto(modetab[CM], width / 2 - 23, ++i), 1, ft_outc);
	ft_putshell("/\\__/ /|  __/| ||  __/| (__ | |_ | (_) || |   ");
	tputs(tgoto(modetab[CM], width / 2 - 23, ++i), 1, ft_outc);
	ft_putshell("\\____/  \\___||_| \\___| ");
	ft_putshell("\\___| \\__| \\___/ |_|by Sconso~");
}

void	ft_printhelp(t_control *list, char **modetab)
{
	t_cursor	cur;

	if (list->state == 0)
	{
		cur.x = (list->width / 2) - 11;
		cur.y = 0;
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|        HELP        |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|                    |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|   + = Select All   |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|  - = Deselect All  |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		ft_putshell("|     / = Search     |");
		tputs(tgoto(modetab[CM], cur.x, cur.y++), 1, ft_outc);
		tputs(modetab[UNDERLINED], 1, ft_outc);
		ft_putshell("|                    |");
		tputs(modetab[CLEAN], 1, ft_outc);
		list->state = 1;
	}
	else
		ft_clear(modetab, list, 1);
}
