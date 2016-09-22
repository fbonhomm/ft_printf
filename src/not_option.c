/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:06:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:12:13 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

void			set_info(void)
{
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	else
		g_info_opt->bl_moins = 0;
	if (is_flag('0') && !is_flag('-'))
		g_info_opt->bl_zero = 1;
	else
		g_info_opt->bl_zero = 0;
}

void			not_option(char **format)
{
	set_info();
	if (g_info_opt->bl_moins)
		bufferisation(NULL, **format, 0);
	print_precision(0);
	if (!g_info_opt->bl_moins)
		bufferisation(NULL, **format, 0);
	init_tmp();
	(*format)++;
	(void)*format;
}
