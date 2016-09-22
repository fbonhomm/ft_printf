/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:13:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:08:38 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				len_string_wchar(wchar_t *swc)
{
	int			len;

	len = 0;
	while (*swc)
	{
		len += ft_wcharlen(*swc);
		swc++;
	}
	return (len);
}

int				nbr_print_c(wchar_t *swc)
{
	int			c;
	int			i;
	int			w;

	c = 0;
	i = 0;
	w = g_tmp->field_width;
	while (*swc)
	{
		if (w)
		{
			w -= ft_wcharlen(*swc);
			if (w < 0)
				break ;
			if (w == 0)
				w--;
		}
		i += ft_wcharlen(*swc);
		c++;
		swc++;
	}
	if (g_tmp->field_width > 0)
		g_tmp->field_width = i;
	return (c);
}

void			print_ls(wchar_t *swc, int nbr_c)
{
	while ((*swc) && (nbr_c > 0))
	{
		ft_putwchar(*swc);
		swc++;
		nbr_c--;
	}
}

int				size_send_to_precision_ls(wchar_t *swc)
{
	if (g_tmp->field_width > 0)
		return (g_tmp->field_width);
	else if (g_tmp->field_width == -1)
		return (0);
	else
		return (len_string_wchar(swc));
}

int				option_ls(void)
{
	wchar_t		*swc;
	int			len;
	int			nbr_c;

	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
	if ((swc = va_arg(g_tmp->ap, wchar_t*)) == NULL)
	{
		bufferisation("(null)", 0, 6);
		return (1);
	}
	len = size_send_to_precision_ls(swc);
	nbr_c = nbr_print_c(swc);
	if (g_info_opt->bl_moins)
		print_ls(swc, nbr_c);
	print_precision(len);
	if (!g_info_opt->bl_moins)
		print_ls(swc, nbr_c);
	return (1);
}
