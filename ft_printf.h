/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:49:51 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 14:27:56 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
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
}				t_flag;

int				ft_vsprintf(char *buf, const char *format, va_list args);
int				ft_printf(const char *format, ...);
t_flag			ft_flags(const char *format, int s, va_list args, int *form);
int				ft_flag(const char format, t_flag flags);
int				ft_width(const char *format, t_flag flags, va_list args, int *form);
int				ft_precision(const char *format, t_flag flags, va_list args, int *form);
int				ft_length(const char *format, t_flag flags, int *form);
int				ft_character(char *buf, va_list args, int *j, const char *format);
void			ft_flag_app(t_flag flags, char *front, char *back, char *str);


#endif
