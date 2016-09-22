/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:12:21 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 18:46:21 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_info_d(char *str)
{
	if (str[0] == '-')
	{
		g_info_opt->bl_plus = 1;
		g_info_opt->bl_c_plus = '-';
	}
	if (is_flag('+'))
	{
		g_info_opt->bl_plus = 1;
		if (str[0] != '-')
			g_info_opt->bl_c_plus = '+';
	}
	if (is_flag('0') && !is_flag('-') && !g_tmp->field_width)
		g_info_opt->bl_zero = 1;
	if ((is_flag(' ')) && (!is_flag('+')) && str[0] && str[0] != '-')
		g_info_opt->bl_space = 1;
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
}

char			*convert_d(void)
{
	int			i;
	char		*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "ll")))
		str = ft_numtoa(va_arg(g_tmp->ap, long long), 10);
	else if (!(ft_strcmp(g_tmp->convert, "l")))
		str = ft_numtoa(va_arg(g_tmp->ap, long), 10);
	else if (!(ft_strcmp(g_tmp->convert, "j")))
		str = ft_numtoa(va_arg(g_tmp->ap, intmax_t), 10);
	else if (!(ft_strcmp(g_tmp->convert, "z")))
		str = ft_numtoa(va_arg(g_tmp->ap, size_t), 10);
	else
	{
		i = va_arg(g_tmp->ap, int);
		if (!(ft_strcmp(g_tmp->convert, "hh")))
			i = (char)i;
		if (!(ft_strcmp(g_tmp->convert, "h")))
			i = (short)i;
		str = ft_numtoa(i, 10);
	}
	return (str);
}

char			*print_d(char *str, int len)
{
	if (g_info_opt->bl_space)
		ft_putchar(' ');
	if (g_info_opt->bl_c_plus)
	{
		ft_putchar(g_info_opt->bl_c_plus);
		g_info_opt->bl_c_plus = '\0';
	}
	ft_put_dec(str, len);
	return (str);
}

int				size_send_to_precision_d(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
		return (ft_strlen(str));
}

int				option_d(void)
{
	int			len;
	char		*str;
	char		*tmp;

	str = convert_d();
	tmp = str;
	set_info_d(str);
	if (g_info_opt->bl_c_plus == '-')
		str++;
	len = size_send_to_precision_d(str);
	if (g_info_opt->bl_moins)
		str = print_d(str, len);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		str = print_d(str, len);
	ft_strdel(&tmp);
	return (1);
}
