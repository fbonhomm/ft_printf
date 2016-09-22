/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:13:18 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:00:13 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				set_info_u(void)
{
	if ((is_flag('0')) && (!is_flag('-')))
		g_info_opt->bl_zero = 1;
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
}

char				*convert_u(void)
{
	unsigned int	i;
	char			*str;

	str = NULL;
	if (!(ft_strcmp(g_tmp->convert, "ll")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long long), 10);
	else if (!(ft_strcmp(g_tmp->convert, "l")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, unsigned long), 10);
	else if (!(ft_strcmp(g_tmp->convert, "j")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, uintmax_t), 10);
	else if (!(ft_strcmp(g_tmp->convert, "z")))
		str = ft_numtoa_unsign(va_arg(g_tmp->ap, ssize_t), 10);
	else
	{
		i = va_arg(g_tmp->ap, unsigned int);
		if (!(ft_strcmp(g_tmp->convert, "hh")))
			i = (unsigned char)i;
		if (!(ft_strcmp(g_tmp->convert, "h")))
			i = (unsigned short)i;
		str = ft_numtoa_unsign(i, 10);
	}
	return (str);
}

int					size_send_to_precision_u(char *str)
{
	if (g_tmp->field_width == -1 && str[0] == '0' && !str[1])
		return (0);
	else
		return (ft_strlen(str));
}

int					option_u(void)
{
	int				len;
	char			*str;
	char			*tmp;

	str = convert_u();
	tmp = str;
	set_info_u();
	len = size_send_to_precision_u(str);
	if (g_info_opt->bl_moins)
		ft_put_dec(str, len);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		ft_put_dec(str, len);
	ft_strdel(&tmp);
	return (1);
}
