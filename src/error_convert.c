/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 20:00:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 16:17:42 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			error_convert(void)
{
	char		*str;

	bufferisation(NULL, '%', 0);
	bufferisation(g_tmp->flag, 0, ft_strlen(g_tmp->flag));
	if (g_tmp->precision != 0)
	{
		str = ft_itoa(g_tmp->precision, 10);
		bufferisation(str, 0, ft_strlen(str));
		ft_strdel(&str);
	}
	bufferisation(NULL, g_tmp->opt, 0);
}
