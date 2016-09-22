/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:05:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 22:05:05 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

int			valid_flag(char c)
{
	int		i;

	i = -1;
	while (++i < MAX_FLAG)
	{
		if (g_flag[i] == c)
			return (1);
	}
	return (0);
}

int			valid_other_flag(char **str, int i0, int i1)
{
	int		j;

	j = 0;
	if ((i0 != 0) || (i1 != 0))
	{
		init_tmp();
		return (0);
	}
	while (valid_flag(**str))
	{
		if (j < LIMIT_FLAG)
			g_tmp->flag[j++] = **str;
		(*str)++;
	}
	g_tmp->flag[j] = '\0';
	return (1);
}
