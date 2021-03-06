/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:06:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/14 23:29:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strrev(char **s)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	j = ft_strlen((*s));
	while (++i < --j)
	{
		c = (*s)[i];
		(*s)[i] = (*s)[j];
		(*s)[j] = c;
	}
}
