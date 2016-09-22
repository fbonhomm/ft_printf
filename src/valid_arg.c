/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:05:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 18:52:11 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

char		*init_var_arg(char **str, int *i0, int *i1)
{
	char	*tmp;

	*i0 = 0;
	*i1 = 0;
	tmp = *str;
	(*str)++;
	return (tmp);
}

int			error_arg(char **str, char *tmp)
{
	if (*(*str - 1) == *tmp && *(*str - 1) != '%')
		*str = tmp;
	return (0);
}

int			end_arg(char **str, char *tmp)
{
	if ((!**str) || (!valid_opt(**str)))
	{
		if ((*(*str - 1) == *tmp && **str) || (!valid_opt(**str) && **str))
			*str = tmp;
		return (0);
	}
	g_tmp->opt = *(*str)++;
	return (1);
}

int			valid_arg(char **str)
{
	int		i[2];
	char	*tmp;

	tmp = init_var_arg(str, &i[0], &i[1]);
	while (**str && !valid_opt(**str))
	{
		if (valid_flag(**str))
		{
			if (!valid_other_flag(str, i[0], i[1]))
				return (0);
		}
		else if ((ft_isdigit(**str)) || (**str == '.'))
		{
			if (!valid_precision(str, &i[0], i[1]))
				return (0);
		}
		else if (valid_convert(**str))
		{
			if (!valid_other_convert(str, &i[1]))
				return (0);
		}
		else
			return (error_arg(str, tmp));
	}
	return (end_arg(str, tmp));
}
