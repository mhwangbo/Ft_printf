/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:28:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 00:20:41 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_decimal(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		form;
	t_chars	*chars;

	form = 0;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 3, args, &form);
	chars->str = ft_itoa(ft_d_cv(flags, args));
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, 3, n);
	return (form + 1);
}
