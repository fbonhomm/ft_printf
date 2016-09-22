/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 22:22:49 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 00:00:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(void)
{
	g_info_opt->bl_plus = 0;
	g_info_opt->bl_zero = 0;
	g_info_opt->bl_hastag = 0;
	g_info_opt->bl_space = 0;
	g_info_opt->bl_moins = 0;
	g_info_opt->bl_c_plus = '\0';
}

void		init_tmp(void)
{
	g_tmp->index = 0;
	g_tmp->precision = 0;
	g_tmp->field_width = 0;
	g_tmp->opt = 0;
	ft_memset(g_tmp->flag, 0, 10);
	ft_memset(g_tmp->convert, 0, 3);
}
