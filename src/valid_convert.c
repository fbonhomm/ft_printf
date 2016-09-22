/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:05:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 19:28:12 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

int			valid_convert(char c)
{
	int		i;

	i = -1;
	while (++i < MAX_CONVERT)
	{
		if (g_convert[i] == c)
		{
			g_tmp->convert[0] = g_convert[i];
			return (1);
		}
	}
	return (0);
}

int			valid_other_convert(char **str, int *i1)
{
	if (*i1 != 0)
		return (0);
	if ((**str == 'l' && *(*str + 1) == 'l') ||
		(**str == 'h' && *(*str + 1) == 'h'))
	{
		(*str)++;
		g_tmp->convert[1] = **str;
	}
	*i1 = 1;
	(*str)++;
	return (1);
}
