/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:31:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 18:19:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c + 'A' - 'a');
	return (c);
}

void		ft_put_toupper(char const *s, int len)
{
	int		i;
	int		j;
	char	tmp[ft_strlen(s)];

	i = 0;
	j = 0;
	while (s[i])
		tmp[j++] = ft_toupper(s[i++]);
	tmp[j] = '\0';
	ft_put_dec(tmp, len);
}
