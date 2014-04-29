/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 23:29:41 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 23:33:03 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fc_str.h>
#include <stdlib.h>

void	ft_default(char **modetab)
{
	free(modetab[8]);
	modetab[8] = ft_strdup("\033[48;5;7m");
	free(modetab[9]);
	modetab[9] = ft_strdup("\033[1;38;5;232m\033[48;5;248m");
	free(modetab[10]);
	modetab[10] = ft_strdup("\033[48;5;247m\033[38;5;7m");
	free(modetab[11]);
	modetab[11] = ft_strdup("\033[48;5;247m\033[1;30m");
	free(modetab[12]);
	modetab[12] = ft_strdup("\033[2m\033[30m");
}

void	ft_hellokitty(char **modetab)
{
	free(modetab[8]);
	modetab[8] = ft_strdup("\033[48;5;13m");
	free(modetab[9]);
	modetab[9] = ft_strdup("\033[38;5;206m\033[48;5;5m");
	free(modetab[10]);
	modetab[10] = ft_strdup("\033[48;5;213m\033[38;5;204m");
	free(modetab[11]);
	modetab[11] = ft_strdup("\033[48;5;213m\033[38;5;124m");
	free(modetab[12]);
	modetab[12] = ft_strdup("\033[38;5;124m");
}

void	ft_darkgoth(char **modetab)
{
	free(modetab[8]);
	modetab[8] = ft_strdup("\033[48;5;0m");
	free(modetab[9]);
	modetab[9] = ft_strdup("\033[1;38;5;232m\033[48;5;235m");
	free(modetab[10]);
	modetab[10] = ft_strdup("\033[48;5;234m\033[38;5;0m");
	free(modetab[11]);
	modetab[11] = ft_strdup("\033[48;5;234m\033[1;30m");
	free(modetab[12]);
	modetab[12] = ft_strdup("\033[2m\033[38;5;234m");
}

void	ft_jamaica(char **modetab)
{
	free(modetab[8]);
	modetab[8] = ft_strdup("\033[48;5;28m");
	free(modetab[9]);
	modetab[9] = ft_strdup("\033[1;38;5;232m\033[48;5;221m");
	free(modetab[10]);
	modetab[10] = ft_strdup("\033[48;5;0m\033[38;5;0m");
	free(modetab[11]);
	modetab[11] = ft_strdup("\033[48;5;221m\033[38;5;0m");
	free(modetab[12]);
	modetab[12] = ft_strdup("\033[2m\033[38;5;10m");
}

void	ft_bsod(char **modetab)
{
	free(modetab[8]);
	modetab[8] = ft_strdup("\033[48;5;20m");
	free(modetab[9]);
	modetab[9] = ft_strdup("\033[1;38;5;15m\033[48;5;20m");
	free(modetab[10]);
	modetab[10] = ft_strdup("\033[48;5;20m\033[38;5;15m");
	free(modetab[11]);
	modetab[11] = ft_strdup("\033[48;5;20m\033[38;5;15m");
	free(modetab[12]);
	modetab[12] = ft_strdup("\033[2m\033[38;5;15m");
}
