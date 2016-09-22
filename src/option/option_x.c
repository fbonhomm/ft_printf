/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:16:20 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:00:17 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				set_info_x(void)
{
	if ((is_flag('0')) && (!is_flag('-')))
		g_info_opt->bl_zero = 1;
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	if (is_flag('#'))
		g_info_opt->bl_hastag = 2;
}

char				*convert_x(void)
{
	unsigned int	i;
	char			*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "ll")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long long), 16);
	else if (!(ft_strcmp(g_tmp->convert, "l")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long), 16);
	else if (!(ft_strcmp(g_tmp->convert, "j")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, uintmax_t), 16);
	else if (!(ft_strcmp(g_tmp->convert, "z")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, ssize_t), 16);
	else
	{
		i = va_arg(g_tmp->ap, unsigned int);
		if (!(ft_strcmp(g_tmp->convert, "hh")))
			i = (unsigned char)i;
		if (!(ft_strcmp(g_tmp->convert, "h")))
			i = (unsigned short)i;
		str = ft_numtoa_unsign(i, 16);
	}
	return (str);
}

int					size_send_to_precision_x(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
		return (ft_strlen(str) + g_info_opt->bl_hastag);
}

int					option_x(void)
{
	int				len;
	char			*str;
	char			*tmp;

	str = convert_x();
	tmp = str;
	set_info_x();
	len = size_send_to_precision_x(str);
	if ((g_info_opt->bl_zero && g_info_opt->bl_hastag && str[0] != '0') ||
			(g_info_opt->bl_moins && g_info_opt->bl_hastag))
		bufferisation("0x", 0, 2);
	if (g_info_opt->bl_moins)
		ft_put_dec(str, len);
	print_precision(len);
	if (!g_info_opt->bl_moins)
	{
		if (!g_info_opt->bl_zero && g_info_opt->bl_hastag &&
				g_tmp->field_width != -1 && str[0] != '0')
			bufferisation("0x", 0, 2);
		ft_put_dec(str, len);
	}
	ft_strdel(&tmp);
	return (1);
}
