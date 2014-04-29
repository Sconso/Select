/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:15:50 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 21:16:56 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <ft_fc_print.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <stdlib.h>

static void		ft_clear_aff(char **mode, t_control *args, struct winsize w)
{
	char	*bg;
	int		i;

	bg = ft_strnewset(w.ws_col, ' ');
	i = -1;
	ft_putshell(mode[BGC]);
	while (++i < w.ws_row)
		ft_putshell(bg);
	free(bg);
	tputs(tgoto(mode[CM], 0, 0), 1, ft_outc);
	i = (w.ws_row - 9 > 0 ? args->size / (w.ws_row - 9) + 1 : 0);
	if (!i || i * (args->maxcol->size + (i * 1)) > w.ws_col)
	{
		if (w.ws_col / 2 - 20 > 0)
			tputs(tgoto(mode[CM], w.ws_col / 2 - 20, w.ws_row / 2), 1, ft_outc);
		ft_puterr("\033[31mTrop d'arguments pour la taille de la fenetre.\n");
		args->usable = -1;
	}
	else
	{
		ft_afflist(args, mode, ft_floor((double)args->size / i), i);
		args->usable = 1;
	}
}

void			ft_clear(char **modetab, t_control *list, char aff)
{
	int					i;
	struct winsize		w;
	static char			**modes;
	static t_control	*args;

	if (modetab != 0 && list != 0)
	{
		modes = modetab;
		args = list;
	}
	args->state = 0;
	if (ioctl(0, TIOCGWINSZ, &w) < 0)
		ft_exit("IOCTL ERROR.\n");
	args->width = w.ws_col;
	args->height = w.ws_row;
	i = -1;
	tputs(tgoto(modes[CM], 0, 0), 1, ft_outc);
	while (++i < w.ws_row)
		tputs(modes[DELETE], 1, ft_outc);
	if (aff)
		ft_clear_aff(modes, args, w);
}
