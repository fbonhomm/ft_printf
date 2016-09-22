/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:12:28 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 18:09:21 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>
# include <inttypes.h>

/*
** Define
*/
# define LIMIT_PRE	1024
# define LIMIT_FLAG	1024
# define MAX_BUF	10000

/*
** Structure
*/
typedef struct		s_tmp
{
	int				index;
	int				precision;
	int				field_width;
	char			opt;
	char			flag[LIMIT_FLAG];
	char			convert[3];
	va_list			ap;
}					t_tmp;
typedef struct		s_info_opt
{
	int				bl_plus;
	int				bl_zero;
	int				bl_hastag;
	int				bl_space;
	int				bl_moins;
	char			bl_c_plus;
}					t_info_opt;
/*
** Global
*/
t_tmp				*g_tmp;
t_info_opt			*g_info_opt;
char				g_buffer[MAX_BUF + 1];
int					g_index;
int					g_size_return;
/*
** ----------- PROTOTYPE -----------
*/
void				loop_primary(char *format);
int					valid_arg(char **str);
int					valid_opt(char c);
int					valid_flag(char c);
int					valid_other_flag(char **str, int i0, int i1);
int					valid_convert(char c);
int					valid_other_convert(char **str, int *i0);
int					valid_precision(char **str, int *i0, int i1);
void				valid_other_precision(char **str, char **t, int *i, int *b);
void				print_precision(int len);
int					is_flag(char c);
void				error_convert();
void				add_flag(char c);
void				print_zero(int len);
void				not_option(char **format);
void				init_info();
void				init_tmp();
void				print_buffer(void);
void				bufferisation(char *str, char c, int len);
/*
** option
*/
int					option_b(void);
int					option_lc(void);
int					option_c(void);
int					option_d(void);
int					option_ld(void);
int					option_i(void);
int					option_o(void);
int					option_lo(void);
int					option_p(void);
int					option_s(void);
int					option_ls(void);
int					option_u(void);
int					option_lu(void);
int					option_x(void);
int					option_lx(void);
/*
** lib
*/
void				ft_putchar_endl(char c);
void				ft_strdel(char **str);
void				ft_put_str(char *s);
void				ft_putchar(char c);
char				*ft_itoa(int n, int base);
size_t				ft_strlen(const char *s);
void				ft_strrev(char **s);
int					ft_atoi(char *str);
int					ft_isdigit(int c);
void				*ft_memset(void *b, int c, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_numlen(int n);
void				ft_put_toupper(char const *s, int len);
void				ft_putwchar(wchar_t wc);
int					ft_wcharlen(wchar_t wc);
char				*ft_strdup(const char *s1);
char				*ft_numtoa(long long n, int base);
char				*ft_numtoa_unsign(unsigned long long n, int base);
int					ft_put(char const *s);
void				ft_put_dec(char *s, int len);
void				*ft_realloc(void *str, size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t n);
void				ft_putnbr(int n);

#endif
