/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:06:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 16:03:09 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_info_b(void)
{
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	else
		g_info_opt->bl_moins = 0;
}

int				option_b(void)
{
	int			c;
	char		*str;

	c = 0;
	set_info_b();
	c = va_arg(g_tmp->ap, int);
	str = ft_itoa(c, 2);
	if (g_info_opt->bl_moins)
		ft_put_dec(str, ft_strlen(str));
	print_precision(ft_strlen(str));
	if (!g_info_opt->bl_moins)
		ft_put_dec(str, ft_strlen(str));
	ft_strdel(&str);
	return (1);
}
