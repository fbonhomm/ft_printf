/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 23:59:04 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/14 23:59:05 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "array.h"

void		add_flag(char c)
{
	int		i;

	i = 0;
	while (g_tmp->flag[i])
		i++;
	g_tmp->flag[i++] = c;
	g_tmp->flag[i] = '\0';
}
