/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:05:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 15:59:37 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	if (!format)
		return (EXIT_FAILURE);
	if (!(g_tmp = (t_tmp*)malloc(sizeof(t_tmp))))
		return (EXIT_FAILURE);
	if (!(g_info_opt = (t_info_opt*)malloc(sizeof(t_info_opt))))
		return (EXIT_FAILURE);
	g_size_return = 0;
	va_start(g_tmp->ap, format);
	loop_primary(format);
	free(g_tmp);
	free(g_info_opt);
	return (g_size_return);
}
