/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:31:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 18:42:53 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_put_str(char *s)
{
	int		len;

	if (!s && !g_tmp->field_width)
	{
		bufferisation("(null)", 0, 6);
		return ;
	}
	if (g_tmp->field_width == -1)
		return ;
	len = ft_strlen(s);
	if (g_tmp->field_width && g_tmp->field_width < len)
		len = g_tmp->field_width;
	if (s)
		bufferisation(s, 0, len);
}
