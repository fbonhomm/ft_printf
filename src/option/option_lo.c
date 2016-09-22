/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_lo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:12:34 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 19:59:46 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_info_lo(char *str)
{
	if ((is_flag('0')) && (!is_flag('-')))
		g_info_opt->bl_zero = 1;
	if ((is_flag(' ')) && (!is_flag('+')) && str[0] && str[0] != '-')
		g_info_opt->bl_space = 1;
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	if (is_flag('#'))
		g_info_opt->bl_hastag = 1;
}

char			*convert_lo(void)
{
	char		*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "l")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long long), 8);
	else
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long), 8);
	return (str);
}

char			*print_lo(char *str, int len)
{
	if ((g_info_opt->bl_hastag && str[0] != '0' && g_tmp->field_width != -1) ||
			(g_tmp->field_width == -1 && g_info_opt->bl_hastag))
		ft_putchar('0');
	ft_put_dec(str, len);
	return (str);
}

int				size_send_to_precision_lo(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
		return (ft_strlen(str));
}

int				option_lo(void)
{
	int			len;
	char		*str;
	char		*tmp;

	str = convert_lo();
	tmp = str;
	set_info_lo(str);
	len = size_send_to_precision_lo(str);
	if (g_info_opt->bl_moins)
		str = print_lo(str, len);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		str = print_lo(str, len);
	ft_strdel(&tmp);
	return (1);
}
