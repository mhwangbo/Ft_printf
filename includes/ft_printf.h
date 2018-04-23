/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:49:51 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 16:58:46 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flag
{
	int			spec;
	int			minus;
	int			zero;
	int			plus;
	int			space;
	int			hash;
	int			width;
	int			precision;
	int			length;
}				t_flag;

typedef struct	s_chars
{
	char		*front;
	char		*back;
	char		*str;
	char		*tmp;
}				t_chars;

typedef struct	s_numbers
{
	int			i;
	int			j;
	int			k;
	int			spec;
}				t_numbers;

int				ft_printf(const char *format, ...);
int				ft_vsprintf(char *buf, const char *format, va_list args,
		t_numbers n);
int				ft_vsprintf_s(const char *format, int i);
int				ft_printf_send(char *buf, va_list args, t_numbers *n,
		const char *format);

t_flag			ft_flags(const char *format, int s, va_list args, int *form);
int				ft_flag(const char format, t_flag *flags);
int				ft_width(const char *format, t_flag *flags, va_list args,
		int **form);
int				ft_precision(const char *format, t_flag *flags,
		va_list args, int **form);
int				ft_length(const char *format, t_flag *flags, int **i);

void			ft_flag_app(t_flag flags, t_chars *chars);
void			ft_hash_a(t_flag *flags, t_chars *chars, int *i, int *sign);
void			ft_plus_a(t_flag flags, t_chars *chars, int *len);
void			ft_width_a(t_flag *flags, t_chars *chars, int *b, int *f);
void			ft_precision_a(t_flag *flags, t_chars *chars, int *len);

int				ft_character(char *buf, va_list args, int *j,
		const char *format);
int				ft_string(char *buf, va_list args, int *j, const char *format);
int				ft_decimal(char *buf, va_list args, int *j, const char *format);
int				ft_unsigned(char *buf, va_list args, int *j,
		const char *format);
int				ft_unsigned_s(const char *format);
void			ft_to_capital(t_chars *chars, const char *format);
int				ft_pointer(char *buf, va_list args, int *j, const char *format);

long long			ft_d_cv(t_flag flags, va_list args);
unsigned long long	ft_un_cv(t_flag flags, va_list args);

void			ft_str_to_buf(t_chars *chars, char *buf, int **j, int s);
t_chars			*ft_chars_malloc(void);
#endif
