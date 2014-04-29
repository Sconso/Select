/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:15:16 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 18:15:18 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_round(double nb)
{
	int		result;

	result = (int)nb;
	if (result < nb - 0.5)
		return (result + 1);
	else
		return (result);
	return (0);
}

int		ft_floor(double nb)
{
	int		result;

	result = (int)nb;
	if (nb > result)
		return (result + 1);
	else
		return (result);
}
