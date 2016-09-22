/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:05:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 19:16:17 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

void		valid_other_precision(char **str, char **t, int *i, int *b)
{
	if (**str == '.')
	{
		(*t)[*i] = '\0';
		g_tmp->precision = ft_atoi(*t);
		*i = 0;
		*b = 1;
	}
	else if (*i < LIMIT_PRE)
	{
		(*t)[*i] = **str;
		*i += 1;
	}
	(*str)++;
}

int			valid_precision(char **str, int *i0, int i1)
{
	int		i;
	int		booleen;
	char	*tabl;

	i = 0;
	booleen = 0;
	if ((*i0 != 0) || (i1 != 0) || (!(tabl = malloc(sizeof(char) * LIMIT_PRE))))
	{
		init_tmp();
		return (0);
	}
	*i0 = 1;
	while ((ft_isdigit(**str)) || (**str == '.'))
		valid_other_precision(str, &tabl, &i, &booleen);
	tabl[i] = '\0';
	if (booleen)
	{
		g_tmp->field_width = ft_atoi(tabl);
		if (!g_tmp->field_width)
			g_tmp->field_width = -1;
	}
	else
		g_tmp->precision = ft_atoi(tabl);
	ft_strdel(&tabl);
	return (1);
}
