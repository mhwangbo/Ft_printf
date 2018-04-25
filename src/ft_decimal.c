/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:28:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 22:34:50 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_decimal(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	t_chars		*chars;
	long long	i;

	form = 0;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 3, args, &form);
	i = ft_d_cv(flags, args);
	chars->str = ft_itoa(i);
	if (i == 0 && flags.pre_e == 1 && flags.precision == 0)
		chars->str++;
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, 3, n);
	ft_chars_free(chars, flags);
	return (form + 1);
}
