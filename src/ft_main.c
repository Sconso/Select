/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:15:24 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 18:48:18 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		main(int ac, char **av)
{
	t_control		*list;
	char			**modetab;

	if (ac < 2)
		ft_exit("Usage : ./ft_select arg1 [...]\n");
	ft_signals();
	modetab = ft_selectorinit(&list, ac, av);
	ft_select(list, modetab);
	return (0);
}
