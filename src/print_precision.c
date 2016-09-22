/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 16:05:11 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:41:00 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

char			print_precision_zero(void)
{
	if (g_info_opt->bl_c_plus)
	{
		ft_putchar(g_info_opt->bl_c_plus);
		g_info_opt->bl_c_plus = '\0';
	}
	if (g_info_opt->bl_space)
	{
		ft_putchar(' ');
		g_info_opt->bl_space = 0;
	}
	return ('0');
}

void			print_precision(int len)
{
	int			i;
	char		c;
	char		str[((unsigned int)len) + g_tmp->precision + 1];

	if (g_tmp->field_width > len)
		len = g_tmp->field_width;
	if ((g_tmp->precision <= 0) || (g_tmp->precision <= len))
		return ;
	len = g_tmp->precision - len;
	if (g_info_opt->bl_plus)
		len--;
	if (g_info_opt->bl_space)
		len--;
	if (len <= 0)
		return ;
	c = ' ';
	i = 0;
	if (g_info_opt->bl_zero)
		c = print_precision_zero();
	while (i < len)
		str[i++] = c;
	str[i] = '\0';
	bufferisation(str, 0, ft_strlen(str));
}
