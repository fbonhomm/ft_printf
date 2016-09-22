/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_lc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:06:25 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/15 21:24:39 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_info_lc(void)
{
	if (is_flag('-'))
		g_info_opt->bl_moins = 1;
}

int				option_lc(void)
{
	wint_t		wc;

	wc = 0;
	set_info_lc();
	wc = va_arg(g_tmp->ap, wint_t);
	if (g_info_opt->bl_moins)
		ft_putwchar(wc);
	print_precision(ft_wcharlen(wc));
	if (!g_info_opt->bl_moins)
		ft_putwchar(wc);
	return (1);
}
