/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:12:39 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:00:02 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				set_info_o(char *str)
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

char				*convert_o(void)
{
	unsigned int	i;
	char			*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "ll")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long long), 8);
	else if (!(ft_strcmp(g_tmp->convert, "l")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long), 8);
	else if (!(ft_strcmp(g_tmp->convert, "j")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, uintmax_t), 8);
	else if (!(ft_strcmp(g_tmp->convert, "z")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, ssize_t), 8);
	else
	{
		i = va_arg(g_tmp->ap, unsigned int);
		if (!(ft_strcmp(g_tmp->convert, "hh")))
			i = (unsigned char)i;
		if (!(ft_strcmp(g_tmp->convert, "h")))
			i = (unsigned short)i;
		str = ft_numtoa_unsign(i, 8);
	}
	return (str);
}

char				*print_o(char *str, int len)
{
	if ((g_info_opt->bl_hastag && str[0] != '0' && g_tmp->field_width != -1) ||
			(g_tmp->field_width == -1 && g_info_opt->bl_hastag))
		bufferisation(NULL, '0', 0);
	ft_put_dec(str, len);
	return (str);
}

int					size_send_to_precision_o(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
		return (ft_strlen(str) + g_info_opt->bl_hastag);
}

int					option_o(void)
{
	int				len;
	char			*str;
	char			*tmp;

	str = convert_o();
	tmp = str;
	set_info_o(str);
	len = size_send_to_precision_o(str);
	if (g_info_opt->bl_moins)
		str = print_o(str, len);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		str = print_o(str, len);
	ft_strdel(&tmp);
	return (1);
}
