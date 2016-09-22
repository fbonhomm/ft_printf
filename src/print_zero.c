/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 20:00:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 16:18:35 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_zero(int len)
{
	int			i;
	char		str[len + 1];

	i = 0;
	if (g_tmp->field_width > len)
	{
		len = g_tmp->field_width - len;
		while (--len >= 0)
			str[i++] = '0';
		str[i] = '\0';
		bufferisation(str, 0, ft_strlen(str));
	}
}
