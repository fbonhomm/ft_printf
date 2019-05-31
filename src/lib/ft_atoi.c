/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:45:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/14 23:12:30 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi(char *str)
{
	int	i;
	int	value;
	int	is_neg;

	i = 0;
	value = 0;
	is_neg = 1;
	if ((!str) || (!str[0]))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		is_neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	value = value * is_neg;
	return (value);
}
