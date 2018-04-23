/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:28:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 14:07:27 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_decimal(char *buf, va_list args, int *j, const char *format)
{
	t_flag	flags;
	int		i;
	int		form;
	t_chars	*chars;

	form = 0;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 3, args, &form);
	i = ft_d_cv(flags, args);
	chars->str = ft_itoa(i);
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, buf, &j, 3);
	return (form + 1);
}
