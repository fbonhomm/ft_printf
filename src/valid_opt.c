/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:05:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 18:58:10 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

int			valid_opt(char c)
{
	int		i;

	i = -1;
	while (++i < MAX_OPT)
	{
		if (g_opt[i] == c)
		{
			g_tmp->index = i;
			return (1);
		}
	}
	return (0);
}
