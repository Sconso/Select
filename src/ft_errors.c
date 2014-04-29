/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 19:01:58 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 20:07:04 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <ft_fc_print.h>
#include <termcap.h>
#include <unistd.h>

void	ft_exit(char *error)
{
	ft_putstr_fd(error, isatty(STDERR_FILENO));
	_exit(0);
}

void	ft_quit(char **modetab, t_control *list, char *error, char *str)
{
	ft_putshell(NONEC);
	ft_clear(modetab, list, 0);
	ft_putshell(NONEC);
	tputs(tgetstr("ve", 0), 1, ft_outc);
	tputs(tgetstr("te", 0), 1, ft_outc);
	ft_setterm();
	if (error)
		ft_puterr(error);
	else if (str)
		ft_putstr(ft_calcret(list));
	_exit(0);
}
