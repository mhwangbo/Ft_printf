/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:49:51 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/04 17:09:19 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_flag
{
	int				spec;
	int				base;
	int				minus;
	int				zero;
	int				plus;
	int				space;
	int				hash;
	int				width;
	int				precision;
	int				pre_e;
	int				length;
	int				o_zero;
	int				sign;
	int				x;
}					t_flag;

typedef struct		s_numbers
{
	int				i;
	int				j;
	int				k;
	int				spec;
	int				return_i;
	int				fd;
}					t_numbers;

/*
** ft_character.c
*/
void				ft_char_width(t_numbers *n, t_flag flags);
int					ft_percent(va_list args, const char *format, t_numbers *n);
int					ft_character(va_list args, const char *format,
		t_numbers *n);

/*
** ft_color.c
*/
void				ft_color(const char *format, t_numbers *n, int *x);
void				ft_color_one(char *str, t_numbers *n, int *x);
void				ft_color_two(char *str, t_numbers *n, int *x);

/*
** ft_decimal.c
*/
void				ft_d_width(t_numbers *n, t_flag flags, int len);
void				ft_d_put(char *str, int len, t_numbers *n, t_flag flags);
void				ft_d_precision(t_flag *flags);
void				ft_d_sign(int *len, long long i, t_flag *flags);
int					ft_decimal(va_list args, const char *format, t_numbers *n);

/*
** ft_etc.c
*/
void				ft_putstr_t(char *s, t_numbers *n);
int					ft_unsigned_s(const char *format, t_flag *flags);
void				ft_un_write(char c, t_numbers *n, t_flag flags);
void				ft_un_put(char *str, t_numbers *n, t_flag flags);
void				ft_un_hash(t_flag *flags, t_numbers *n);

/*
** ft_flags.c
*/
t_flag				ft_flags(const char *format, int s,
		va_list args, int *form);

/*
** ft_flags_detail.c
*/
int					ft_length(const char *format, t_flag *flags, int **i);
int					ft_precision(const char *format, t_flag *flags,
		va_list args, int **f);
int					ft_width(const char *format, t_flag *flags,
		va_list args, int **form);
int					ft_flag(const char format, t_flag *flags);

/*
** ft_floating_hex.c
*/
int					ft_floating_hex(va_list args, const char *format, t_numbers *n);
char				*ft_f_weight(char *str, char type);
char				*ft_ftoa_hex(double val, t_flag *flags, char type);
void				delete_zero(char *tmp);

/*
** ft_floating_hex_two.c
*/
void				hex_prec(t_flag *flags, double val, char **str, char type);
void				get_a_expo(double val, char type, char **str_t);

/*
** ft_floating_o.c
*/
char				*ft_ftoa(long double val, t_flag *flags);
void				ft_f_width(t_numbers *n, t_flag flags, int len);
int					ft_floating_o(va_list args, const char *format,
		t_numbers *n);

/*
** ft_length.c
*/
long long			ft_d_cv(t_flag flags, va_list args);
unsigned long long	ft_un_cv(t_flag flags, va_list args);
long double			ft_f_cv(t_flag flags, va_list args);

/*
** ft_non_print.c
*/
int					ft_non_print(va_list args, const char *format,
		t_numbers *n);
void				ft_non_print_one(char c, t_numbers *n);
void				ft_non_print_two(char c, t_numbers *n);
void				ft_non_print_three(char c, t_numbers *n);

/*
** ft_pointer.c
*/
void				ft_pointer_put(char *str, int len, t_numbers *n);
int					ft_pointer(va_list args, const char *format, t_numbers *n);

/*
** ft_printf.c
*/
int					ft_printf_send(va_list args, t_numbers *n,
		const char *format);
int					ft_vsprintf_s(const char *format, int i);
int					ft_vsprintf(const char *format, va_list args, t_numbers *n);
int					ft_printf(const char *format, ...);

/*
** ft_string.c
*/
void				ft_str_null(t_numbers *n, t_flag flag);
void				ft_str_put(char *str, int len, t_numbers *n);
void				ft_str_width(t_numbers *n, t_flag flags, int len);
void				ft_string_s(t_numbers *n, t_flag flags, char *str, int len);
int					ft_string(va_list args, const char *format, t_numbers *n);

/*
** ft_unsigned.c
*/
void				ft_unsigned_ss(unsigned long long i, t_flag *flags,
		char *str);
void				ft_unsigned_order(t_flag *flags, t_numbers *n, char *str,
		int len);
int					ft_unsigned(va_list args, const char *format, t_numbers *n);

/*
** ft_wide_char_str.c
*/
void				ft_putwchar(char c, t_numbers *n);
void				ft_putwc(wchar_t wc, t_numbers *n);
int					ft_wide_char(va_list args, int form, t_flag flags,
		t_numbers *n);

/*
** ft_wide_str.c
*/
void				ft_wstr_put(wchar_t *str, int len, t_numbers *n);
int					ft_wstrlen(const wchar_t *s);
wchar_t				*ft_wstrdup(wchar_t *ws);
int					ft_wide_str(va_list args, int form, t_flag flags,
		t_numbers *n);
#endif
