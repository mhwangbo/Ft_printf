/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:28:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/19 13:42:40 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_decimal(char *buf, va_list args, int *j, const char *format)
{
	t_flag	flags;
	int		form;
	t_chars	*chars;

	chars = ft_chars_malloc();
	form = va_arg(args, int);
	chars->str = ft_itoa(form);
	form = 0;
	flags = ft_flags(format, 3, args, &form);
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, buf, &j, 3);
	return (form + 1);
}
