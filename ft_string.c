/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:50:38 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/18 21:01:03 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_string(char *buf, va_list args, int *j, const char *format)
{
	t_flag	flags;
	int		form;
	int		i;
	t_chars	*chars;

	form = 0;
	i = -1;
	chars = ft_chars_malloc();
/*	chars = ft_memalloc(sizeof(t_chars) * 1);
	chars->front = ft_memalloc(256);
	chars->back = ft_memalloc(256);
	chars->str = ft_memalloc(256);
	chars->tmp = ft_memalloc(256); */
	flags = ft_flags(format, 2, args, &form);
	chars->str = va_arg(args, char*);
	ft_flag_app(flags, chars->front, chars->back, chars->str);
	if (flags.precision > 0)
	{
		while (++i < flags.precision)
			chars->tmp[i] = chars->str[i];
	}
	else
		chars->tmp = chars->str;
	chars->str = ft_strjoin(chars->front, chars->tmp);
	chars->str = ft_strjoin(chars->str, chars->back);
	ft_str_to_buf(chars->str, buf, &j);
	return (form);
}
