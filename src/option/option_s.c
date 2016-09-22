/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:12:54 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 18:41:36 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"
#include "pointer_funct.h"

void			set_info_s(void)
{
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	if (is_flag('0') && !is_flag('-'))
		g_info_opt->bl_zero = 1;
}

char			*convert_s(void)
{
	char		*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "l")))
	{
		g_tmp->convert[0] = '\0';
		g_tmp->opt = 'S';
		g_funct_opt[(++g_tmp->index)]();
	}
	else
	{
		str = va_arg(g_tmp->ap, char*);
		if ((!str) && !g_tmp->field_width)
		{
			if (g_tmp->precision >= 6)
				g_tmp->precision -= 6;
			else
				g_tmp->precision = 0;
		}
	}
	return (str);
}

int				size_send_to_precision_s(char *str)
{
	if (g_tmp->field_width > 0 && g_tmp->field_width < (int)ft_strlen(str))
		return (g_tmp->field_width);
	if (g_tmp->field_width > (int)ft_strlen(str))
	{
		g_tmp->field_width = ft_strlen(str);
		return (g_tmp->field_width);
	}
	if ((((int)(ft_strlen(str) - g_tmp->field_width)) < 0) ||
			(g_tmp->field_width == -1))
		return (0);
	if (g_tmp->field_width <= 0 && g_tmp->field_width < (int)ft_strlen(str))
		return (ft_strlen(str));
	return (0);
}

int				option_s(void)
{
	int			len;
	char		*str;

	str = convert_s();
	if (g_tmp->opt == 'S')
		return (1);
	set_info_s();
	len = size_send_to_precision_s(str);
	if (g_info_opt->bl_moins)
		ft_put_str(str);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		ft_put_str(str);
	return (1);
}
