/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_lu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:13:12 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 19:59:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_info_lu(void)
{
	if ((is_flag('0')) && (!is_flag('-')))
		g_info_opt->bl_zero = 1;
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
}

char			*convert_lu(void)
{
	char		*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "l")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long long), 10);
	else
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long), 10);
	return (str);
}

int				size_send_to_precision_lu(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
		return (ft_strlen(str));
}

int				option_lu(void)
{
	int			len;
	char		*str;
	char		*tmp;

	str = convert_lu();
	tmp = str;
	set_info_lu();
	len = size_send_to_precision_lu(str);
	if (g_info_opt->bl_moins)
		ft_put_dec(str, len);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		ft_put_dec(str, len);
	ft_strdel(&tmp);
	return (1);
}
