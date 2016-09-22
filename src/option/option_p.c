/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:12:47 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:45:13 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					set_info_p(void)
{
	if ((is_flag('0')) && (!is_flag('-')))
		g_info_opt->bl_zero = 1;
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	g_info_opt->bl_hastag = 1;
}

char					*convert_p(void)
{
	char				*str;
	unsigned long long	arg;

	str = NULL;
	arg = va_arg(g_tmp->ap, unsigned long long);
	str = ft_numtoa_unsign(arg, 16);
	return (str);
}

void					print_p(int i, char *str, int len)
{
	if (i == 1)
	{
		if (g_info_opt->bl_c_plus)
		{
			ft_putchar(g_info_opt->bl_c_plus);
			g_info_opt->bl_c_plus = '\0';
		}
		bufferisation("0x", 0, 2);
	}
	if (i == 2)
	{
		if (g_info_opt->bl_c_plus)
			ft_putchar(g_info_opt->bl_c_plus);
		if (!g_info_opt->bl_zero)
			bufferisation("0x", 0, 2);
		ft_put_dec(str, len);
	}
}

int						size_send_to_precision_p(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
	{
		g_tmp->field_width += 2;
		if (str)
			return (ft_strlen(str) + 2);
		return (2);
	}
}

int						option_p(void)
{
	int					len;
	char				*str;
	char				*tmp;

	str = convert_p();
	tmp = str;
	set_info_p();
	len = size_send_to_precision_p(str);
	if (g_info_opt->bl_space && str)
		ft_putchar(' ');
	if (g_info_opt->bl_moins && str)
	{
		print_p(1, NULL, 0);
		ft_put_dec(str, len);
	}
	if (g_info_opt->bl_zero && !g_info_opt->bl_moins && str)
		print_p(1, NULL, 0);
	print_precision(len);
	if (!g_info_opt->bl_moins && str)
		print_p(2, str, len);
	ft_strdel(&tmp);
	return (1);
}
