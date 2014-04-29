/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:14:40 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 18:38:48 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_str.h>
#include <ft_fc_print.h>
#include <unistd.h>

void	ft_putshell(char *str)
{
	int		size;

	size = ft_strlen(str);
	write(isatty(STDOUT_FILENO), str, size);
}

void	ft_puterr(char *str)
{
	int		size;

	size = ft_strlen(str);
	write(2, str, size);
	ft_putshell("\033[0m");
}

int		ft_outc(int c)
{
	ft_putchar_fd(c, isatty(STDOUT_FILENO));
	return (0);
}
