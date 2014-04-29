/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 17:40:55 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 23:28:39 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define ESC (buf[0] == 27 && !buf[1])
# define ARROW (buf[0] == 27 && buf[1] == 91 && !buf[3])
# define SPACE (buf[0] == ' ' && !buf[1])
# define BACKSPACE (buf[0] == 127 && !buf[1])
# define SUPPR (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126)
# define ENTER (buf[0] == '\n' && !buf[1])
# define MINUS (buf[0] == '-' && !buf[1])
# define PLUS (buf[0] == '+' && !buf[1])
# define SLASH (buf[0] == '/' && !buf[1])
# define QUESTIONMARK (buf[0] == '?' && !buf[1])
# define NONEC "\033[0m"

typedef enum	e_modes
{
	UNDERLINED,
	NOT_UNDERLINED,
	REVERSE_VIDEO,
	NOT_REVERSE,
	CLEAN,
	CLEAR,
	DELETE,
	CM,
	BGC,
	LISTC,
	LINEC,
	SEARCHC,
	LOGOC
}				t_modes;

typedef struct		s_args
{
	char			*name;
	char			selected;
	int				size;
	int				x;
	int				y;
	struct s_args	*next;
	struct s_args	*prev;
}					t_args;

typedef struct		s_control
{
	t_args			*first;
	t_args			*last;
	t_args			*active;
	int				size;
	t_args			*maxcol;
	int				width;
	int				height;
	char			usable;
	char			state;
}					t_control;

typedef struct		s_cursor
{
	unsigned int	x;
	unsigned int	y;
}					t_cursor;

/*
** ft_afflist.c
*/
void		ft_afflist(t_control *list, char **mode, int lines, int colsnb);

/*
** ft_clear.c
*/
void		ft_clear(char **modetab, t_control *list, char aff);

/*
** ft_dlist.c
*/
t_control		*ft_newlist(void);
t_args			*ft_pushlast(t_control *list, char *name);
void			ft_printlist(t_control *list, char way);
void			ft_delete_node(t_control *list, t_args *node);

/*
** ft_errors.c
*/
void		ft_exit(char *error);
void		ft_quit(char **modetab, t_control *list, char *error, char *str);

/*
** ft_keys.c
*/
void		ft_keys(char *buf, t_control *list, char **modetab);

/*
** ft_maths.c
*/
int			ft_round(double nb);
int			ft_floor(double nb);

/*
** ft_move.c
*/
void		ft_changeactive(t_control *list, t_args *new, char **modetab);
void		ft_changecol(t_control *list, char mode, char **modetab);

/*
** ft_print.c
*/
void		ft_putshell(char *str);
void		ft_puterr(char *str);
int			ft_outc(int c);

/*
** ft_printthings.c
*/
void		ft_afflogo(int width, char **modetab, char mode);
void		ft_printhelp(t_control *list, char **modetab);

/*
** ft_search.c
*/
void		ft_search(t_control *list, char **modetab);

/*
** ft_select.c
*/
char		*ft_calcret(t_control *list);
void		ft_addselected(t_control *list, char **modetab);
void		ft_multiselect(t_control *list, char mode, char **modetab);
void		ft_select(t_control *list, char **modetab);

/*
** ft_signal.c
*/
void		ft_signals(void);

/*
** ft_skins.c
*/
void		ft_default(char **modetab);
void		ft_hellokitty(char **modetab);
void		ft_darkgoth(char **modetab);
void		ft_jamaica(char **modetab);
void		ft_bsod(char **modetab);

/*
** ft_skinsinit.c
*/
void		ft_selectskin(t_control *list, char **modetab);



/*
** ft_termoption
*/
void		ft_setterm(void);
char		**ft_selectorinit(t_control **list, int ac, char **av);

/*
** ft_utilities.c
*/
char		*ft_clean3join(char **s1, char *s2, char *s3);
char		*ft_strnewset(int size, char c);
#endif /* FT_SELECT_H  */
