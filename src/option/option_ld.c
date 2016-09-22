/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_ld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:06:29 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 19:59:42 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_info_ld(char *str)
{
	if ((is_flag('0')) && (!is_flag('-')))
		g_info_opt->bl_zero = 1;
	if ((is_flag(' ')) && (!is_flag('+')) && str[0] && str[0] != '-')
		g_info_opt->bl_space = 1;
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	if (is_flag('#') && str[0] != '0')
		g_info_opt->bl_hastag = 1;
}

char			*convert_ld(void)
{
	char		*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "l")))
		str = ft_numtoa(va_arg(g_tmp->ap, long long), 10);
	else
		str = ft_numtoa(va_arg(g_tmp->ap, long), 10);
	return (str);
}

char			*print_ld(char *str, int len)
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

int				size_send_to_precision_ld(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
		return (ft_strlen(str));
}

int				option_ld(void)
{
	int			len;
	char		*str;
	char		*tmp;

	str = convert_ld();
	tmp = str;
	set_info_ld(str);
	len = size_send_to_precision_ld(str);
	if (g_info_opt->bl_c_plus == '-')
		str++;
	if (g_info_opt->bl_moins)
		str = print_ld(str, len);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		str = print_ld(str, len);
	ft_strdel(&tmp);
	return (1);
}
