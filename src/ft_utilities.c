/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:13:42 by sconso            #+#    #+#             */
/*   Updated: 2014/01/12 18:13:44 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_fc_str.h>
#include <ft_fc_mem.h>

char	*ft_clean3join(char **s1, char *s2, char *s3)
{
	int		size;
	int		i;
	char	*str;

	if (!*s1 || !s2 || !s3)
		return (0);
	size = ft_strlen(*s1) + ft_strlen(s2) + ft_strlen(s3);
	str = (char *)malloc(size + 1 * sizeof(*str));
	if (str == 0)
		return (0);
	i = 0;
	while (**s1 && (*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	while (**s1 && *s2)
		str[i++] = *s2++;
	while (*s3)
		str[i++] = *s3++;
	str[i] = 0;
	free(*s1);
	return (str);
}

char	*ft_strnewset(int size, char c)
{
	char	*str;

	str = (char *)malloc((size + 1) * sizeof(*str));
	ft_memset(str, c, size);
	str[size] = 0;
	return (str);
}
