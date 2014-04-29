/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:14:11 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 23:04:55 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <termcap.h>

static void		ft_backspace(char **str)
{
	tputs(tgetstr("bw", 0), 1, ft_outc);
	tputs(tgetstr("le", 0), 1, ft_outc);
	tputs(tgetstr("dc", 0), 1, ft_outc);
	(*str)[ft_strlen(*str) - 1] = 0;
}

static int		ft_searching(char *buf, t_control *list, char **str)
{
	t_args		*node;
	int			size;

	if (buf[0] == '\n' && !buf[1])
	{
		size = list->size;
		node = list->first;
		while (size--)
		{
			if (ft_strstr(node->name, *str))
				node->selected = 1;
			node = node->next;
		}
		return (-1);
	}
	else if (buf[0] == 127 && !buf[1] && **str)
		ft_backspace(str);
	else if (buf[0] == 27 && !buf[1])
		return (-1);
	else if (ft_isprint(buf[0]) && !buf[1])
	{
		ft_putshell(buf);
		*str = ft_clean3join(str, "", buf);
	}
	return (0);
}

void			ft_search(t_control *list, char **modetab)
{
	char	buf[5];
	int		ret;
	char	*str;

	str = (char *)malloc((list->width + 1) * sizeof(*str));
	ft_memset(str, ' ', list->width);
	str[list->width] = 0;
	ft_memmove(str, "Search > ", 9);
	tputs(tgoto(modetab[CM], 0, list->height), 1, ft_outc);
	ft_putshell(modetab[SEARCHC]);
	ft_putshell(str);
	free(str);
	str = ft_strdup("\0");
	tputs(tgoto(modetab[CM], 9, list->height), 1, ft_outc);
	while ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = 0;
		if (ft_searching(buf, list, &str) == -1)
			break ;
		ft_bzero(buf, 5);
	}
	ft_putshell(NONEC);
	ft_clear(modetab, list, 1);
	free(str);
}
