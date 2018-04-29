/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:49:51 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/29 00:55:13 by mhwangbo         ###   ########.fr       */
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

typedef struct		s_chars
{
	char			*front;
	char			*back;
	char			*str;
	char			*tmp;
}					t_chars;

typedef struct		s_numbers
{
	int				i;
	int				j;
	int				k;
	int				spec;
	int				return_i;
}					t_numbers;

int					ft_printf(const char *format, ...);
int					ft_vsprintf(const char *format, va_list args,
		t_numbers *n);
int					ft_vsprintf_s(const char *format, int i);
int					ft_printf_send(va_list args, t_numbers *n,
		const char *format);

t_flag				ft_flags(const char *format, int s, va_list args,
		int *form);
int					ft_flag(const char format, t_flag *flags);
int					ft_width(const char *format, t_flag *flags, va_list args,
		int **form);
int					ft_precision(const char *format, t_flag *flags,
		va_list args, int **form);
int					ft_length(const char *format, t_flag *flags, int **i);

void				ft_flag_app(t_flag flags, t_chars *chars);
void				ft_flag_app_s(t_flag fl, t_chars *chars, int *f);
void				ft_flag_app_ss(t_flag *fl, t_chars *chars, int *f);
void				ft_hash_a(t_flag *flags, t_chars *chars, int *i);
void				ft_plus_a(t_flag *flags);
void				ft_width_a(t_flag *flags, t_chars *chars, int *b, int *f);
void				ft_width_change(t_flag *flags);
void				ft_precision_a(t_flag *flags, t_chars *chars, int *len);

int					ft_character(va_list args, const char *format,
		t_numbers *n);
void				ft_char_width(t_numbers *n, t_flag flags);

int					ft_string(va_list args, const char *format, t_numbers *n);
void				ft_str_width(t_numbers *n, t_flag flags, int len);
void				ft_str_put(char *str, int lne, t_numbers *n);

int					ft_decimal(va_list args, const char *format, t_numbers *n);
void				ft_d_width(t_numbers *n, t_flag flags, int len);
int					ft_unsigned(va_list args, const char *format, t_numbers *n);
//int					ft_unsigned_s(const char *format);
//void				ft_to_capital(t_chars *chars, const char *format);
int					ft_pointer(va_list args, const char *format, t_numbers *n);
int					ft_percent(va_list args, const char *format, t_numbers *n);

int					ft_wide_char(va_list args, int form, t_flag flags,
		t_numbers *n);
void				ft_putwc(wchar_t wc, t_numbers *n);
void				ft_putwchar(char c, t_numbers *n);
int					ft_wide_str(va_list args, int form, t_flag flags,
		t_numbers *n);

long long			ft_d_cv(t_flag flags, va_list args);
unsigned long long	ft_un_cv(t_flag flags, va_list args);

void				ft_putstr_t(char *s, t_numbers *n);

void				ft_str_to_buf(t_chars *chars, t_numbers *n);
t_chars				*ft_chars_malloc(void);
void				ft_chars_free(t_chars *chars);
#endif
