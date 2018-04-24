/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:36:12 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 16:12:58 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pointer(va_list args, const char *format, t_numbers *n)
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
	chars->str = ft_llitoa_base(int_v, 16);
	if (int_v == 0)
	{
		chars->str[0] = '0';
		flags.o_zero = 1;
		flags.hash = 0;
	}
	ft_flag_app(flags, chars);
	chars->front = ft_strjoin("0x", chars->front);
	ft_str_to_buf(chars, 1, n);
	free(chars);
	return (form + 1);
}
