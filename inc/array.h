/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:11:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 21:02:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# define MAX_OPT		15
# define MAX_FLAG		5
# define MAX_CONVERT	4

/*
** Tableaux
*/
static const char		g_opt[MAX_OPT] =
{
	'b',
	'c',
	'C',
	'd',
	'D',
	'i',
	'o',
	'O',
	'p',
	's',
	'S',
	'u',
	'U',
	'x',
	'X'
};
static const char		g_flag[MAX_FLAG] =
{
	' ',
	'#',
	'+',
	'-',
	'0'
};
static const char		g_convert[MAX_CONVERT] =
{
	'h',
	'j',
	'l',
	'z'
};

#endif
