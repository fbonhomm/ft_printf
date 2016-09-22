/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_primary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:05:34 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 20:45:24 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"
#include "pointer_funct.h"

void		insert_arg(void)
{
	init_info();
	if (!g_funct_opt[g_tmp->index]())
		error_convert();
	init_tmp();
}

void		loop_primary(char *format)
{
	g_index = 0;
	init_tmp();
	while (*format)
	{
		if (g_index >= MAX_BUF)
			print_buffer();
		if (*format == '%' && *(format + 1) == '%' && (format++))
			ft_putchar(*(format++));
		else if (*format == '%' && valid_arg(&format))
			insert_arg();
		else if (*format && ((g_tmp->precision) || (g_tmp->field_width)))
			not_option(&format);
		else if (*format)
			ft_putchar(*(format++));
	}
	print_buffer();
}
