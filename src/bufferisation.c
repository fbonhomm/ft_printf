/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:28:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 21:00:45 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_buffer(void)
{
	g_buffer[g_index] = '\0';
	ft_put(g_buffer);
	g_index = 0;
}

void			bufferisation(char *str, char c, int len)
{
	if (g_index >= MAX_BUF)
		print_buffer();
	if (str)
	{
		if (len < (int)ft_strlen(str))
			g_size_return += len;
		else
			g_size_return += ft_strlen(str);
		while (*str && len)
		{
			if (g_index >= MAX_BUF)
				print_buffer();
			g_buffer[g_index++] = *(str++);
			len--;
		}
	}
	else
	{
		g_size_return++;
		if (c)
			g_buffer[g_index++] = c;
	}
}
