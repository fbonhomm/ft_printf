/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:06:20 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 16:18:56 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"
#include "pointer_funct.h"

void			set_info_c(void)
{
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	if (is_flag('0') && !is_flag('-'))
		g_info_opt->bl_zero = 1;
}

void			set_to_ls(void)
{
	g_tmp->convert[0] = '\0';
	g_tmp->opt = 'C';
	g_funct_opt[(++g_tmp->index)]();
}

int				option_c(void)
{
	int			c;

	c = 0;
	set_info_c();
	if (!(ft_strcmp(g_tmp->convert, "l")))
		set_to_ls();
	else
	{
		c = va_arg(g_tmp->ap, int);
		if (g_info_opt->bl_moins)
			bufferisation(NULL, c, 0);
		if (g_tmp->field_width > 1)
			g_tmp->field_width = 1;
		print_precision(1);
		if (!g_info_opt->bl_moins)
			bufferisation(NULL, c, 0);
	}
	return (1);
}
