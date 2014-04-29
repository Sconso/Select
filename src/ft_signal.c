/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:13:58 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 21:06:24 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ft_select.h>
#include <termios.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <stdlib.h>

static void		ft_sigtstp(void)
{
	struct termios		term;
	char				stop[2];

	if (tcgetattr(0, &term) < 0)
		ft_exit("Getattr error.\n");
	stop[0] = term.c_cc[VSUSP];
	stop[1] = 0;
	ft_putshell(NONEC);
	ft_clear(0, 0, 0);
	ft_putshell(NONEC);
	tputs(tgetstr("ve", 0), 1, ft_outc);
	tputs(tgetstr("te", 0), 1, ft_outc);
	ft_setterm();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, stop);
}

static void		ft_sigcont(void)
{
	ft_signals();
	tputs(tgetstr("ti", 0), 1, ft_outc);
	tputs(tgetstr("vi", 0), 1, ft_outc);
	ft_setterm();
	tputs(tgetstr("cl", 0), 1, ft_outc);
	ft_clear(0, 0, 1);
}

static void		ft_handler(int s)
{
	if (s == SIGTSTP)
		ft_sigtstp();
	else if (s == SIGCONT)
		ft_sigcont();
	else if (s == SIGWINCH)
		ft_clear(0, 0, 1);
	else if (s == SIGINT || s == SIGTERM || s == SIGQUIT || s == SIGABRT)
		ft_quit(0, 0, "Forced quit.\n", 0);
	else if (s == SIGKILL || s == SIGHUP)
		ft_quit(0, 0, "Forced quit.\n", 0);
	else if (s == SIGILL || s == SIGTRAP || s == SIGFPE || s == SIGBUS)
		ft_quit(0, 0, "Fatal error !\n", 0);
	else if (s == SIGSEGV || s == SIGSYS || s == SIGPIPE)
		ft_quit(0, 0, "Fatal error !\n", 0);
	else if (s == SIGTTIN || s == SIGTTOU || s == SIGXCPU || s == SIGXFSZ)
		ft_quit(0, 0, "Fatal error !\n", 0);
}


void			ft_signals(void)
{
	signal(SIGTSTP, ft_handler);
	signal(SIGCONT, ft_handler);
	signal(SIGWINCH, ft_handler);
	signal(SIGINT, ft_handler);
	signal(SIGTERM, ft_handler);
	signal(SIGQUIT, ft_handler);
	signal(SIGABRT, ft_handler);
	signal(SIGKILL, ft_handler);
	signal(SIGHUP, ft_handler);
	signal(SIGILL, ft_handler);
	signal(SIGTRAP, ft_handler);
	signal(SIGFPE, ft_handler);
	signal(SIGBUS, ft_handler);
	signal(SIGSEGV, ft_handler);
	signal(SIGSYS, ft_handler);
	signal(SIGPIPE, ft_handler);
	signal(SIGTTIN, ft_handler);
	signal(SIGTTOU, ft_handler);
	signal(SIGXCPU, ft_handler);
	signal(SIGXFSZ, ft_handler);
}
