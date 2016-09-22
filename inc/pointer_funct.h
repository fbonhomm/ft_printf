/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_funct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:11:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 21:02:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTER_FUNCT_H
# define POINTER_FUNCT_H

# define MAX_OPT	15

/*
** Tableaux de pointeur sur fonction
*/
static int				(*g_funct_opt[MAX_OPT])(void) =
{
	option_b,
	option_c,
	option_lc,
	option_d,
	option_ld,
	option_i,
	option_o,
	option_lo,
	option_p,
	option_s,
	option_ls,
	option_u,
	option_lu,
	option_x,
	option_lx
};

#endif
