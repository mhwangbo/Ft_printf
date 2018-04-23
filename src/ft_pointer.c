/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:36:12 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 15:03:35 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pointer(char *buf, va_list args, int *j, const char *format)
{
	t_flag		flags;
	int			form;
	t_chars		*chars;
	uintmax_t	int_v;

	form = 0;
	ft_bzero(&flags, sizeof(t_flag));
	chars = ft_chars_malloc();
	while (!ft_strchr("sSpdDioOuUxXcC", format[form]))
		form++;
	int_v = (uintmax_t)va_arg(args, void*);
	chars->str = ft_uitoa_base(int_v, 16);
	flags.width = 8;
	flags.zero = 1;
	flags.spec = 5;
	ft_flag_app(flags, chars);
	chars->front = ft_strjoin("0x1", chars->front);
	ft_str_to_buf(chars, buf, &j, 1);
	return (form + 1);
}