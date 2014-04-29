/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 17:57:15 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 21:20:38 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_calcret(t_control *list)
{
	char	*str;
	t_args	*node;
	int		i;

	i = list->size;
	node = list->first;
	str = ft_strdup("");
	while (i--)
	{
		if (node->selected)
			str = ft_clean3join(&str, " ", node->name);
		node = node->next;
	}
	return (str);
}

void	ft_addselected(t_control *list, char **modetab)
{
	t_args		*node;

	node = list->active;
	node->selected = (node->selected ? 0 : 1);
	ft_putshell(modetab[LISTC]);
	tputs(tgoto(modetab[CM], node->x, node->y), 1, ft_outc);
	if (node->selected)
		tputs(modetab[REVERSE_VIDEO], 1, ft_outc);
	ft_putshell(node->name);
	tputs(modetab[CLEAN], 1, ft_outc);
	tputs(tgoto(modetab[CM], node->next->x, node->next->y), 1, ft_outc);
	ft_putshell(modetab[LISTC]);
	tputs(modetab[UNDERLINED], 1, ft_outc);
	if (node->next->selected)
		tputs(modetab[REVERSE_VIDEO], 1, ft_outc);
	ft_putshell(node->next->name);
	tputs(modetab[CLEAN], 1, ft_outc);
	list->active = node->next;
}

void	ft_multiselect(t_control *list, char mode, char **modetab)
{
	t_args		*node;
	int			size;

	node = list->first;
	size = list->size;
	while (size--)
	{
		node->selected = (mode ? 1 : 0);
		node = node->next;
	}
	ft_clear(modetab, list, 1);
}

void	ft_select(t_control *list, char **modetab)
{
	char			buf[5];
	int				ret;

	while ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = 0;
		if (ESC)
			ft_quit(modetab, list, 0, 0);
		if (list->usable == -1)
			continue ;
		ft_keys(buf, list, modetab);
		if (list->size == 0)
			ft_quit(modetab, list, "Aucun argument restant\n", 0);
		ft_bzero(buf, 5);
	}
}
