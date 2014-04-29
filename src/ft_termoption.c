/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termoption.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:13:48 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 23:08:42 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <ft_fc_str.h>
#include <termios.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

static char		**ft_setmodetab(void)
{
	char	**modetab;

	modetab = (char **)malloc(14 * sizeof(char *));
	modetab[13] = 0;
	if (modetab)
	{
		modetab[0] = tgetstr("us", 0);
		modetab[1] = tgetstr("ue", 0);
		modetab[2] = tgetstr("so", 0);
		modetab[3] = tgetstr("se", 0);
		modetab[4] = tgetstr("me", 0);
		modetab[5] = tgetstr("cl", 0);
		modetab[6] = tgetstr("dl", 0);
		modetab[7] = tgetstr("cm", 0);
		modetab[8] = ft_strdup("\033[48;5;7m");
		modetab[9] = ft_strdup("\033[1;38;5;232m\033[48;5;248m");
		modetab[10] = ft_strdup("\033[48;5;247m\033[38;5;7m");
		modetab[11] = ft_strdup("\033[48;5;247m\033[1;30m");
		modetab[12] = ft_strdup("\033[2m\033[30m");
	}
	return (modetab);
}

static void		ft_getterm(void)
{
	char	*termtype;
	int		success;

	if ((termtype = getenv("TERM")) == 0)
		ft_exit("No TERM in env.\n");
	success = tgetent(NULL, termtype);
	if (success < 0)
		ft_exit("Could not access the Termcap database.\n");
	else if (!success)
	{
		ft_puterr("Terminal type '");
		ft_puterr(termtype);
		ft_puterr("' is not defined.\n");
	}
}

void			ft_setterm(void)
{
	static struct termios		*old;
	struct termios				new;

	if (old == NULL)
	{
		old = (struct termios *)malloc(sizeof(*old));
		if (tcdrain(STDIN_FILENO) < 0 || tcgetattr(0, old) < 0)
			ft_exit("Getattr error.\n");
		new = *old;
		new.c_lflag &= ~(ICANON | ECHO);
		new.c_lflag |= ISIG;
		new.c_cc[VMIN] = 1;
		new.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSADRAIN, &new) < 0)
			ft_exit("Setattr error.\n");
	}
	else
	{
		if (tcsetattr(0, TCSADRAIN, old) < 0)
			ft_exit("Setattr error.\n");
		free(old);
		old = NULL;
	}
}

char			**ft_selectorinit(t_control **list, int ac, char **av)
{
	char	**modetab;

	*list = ft_newlist();
	while (--ac)
		ft_pushlast(*list, *(++av));
	ft_getterm();
	ft_setterm();
	modetab = ft_setmodetab();
	tputs(tgetstr("ti", 0), 1, ft_outc);
	tputs(tgetstr("vi", 0), 1, ft_outc);
	tputs(modetab[CLEAR], 1, ft_outc);
	ft_clear(modetab, *list, 1);
	return (modetab);
}
