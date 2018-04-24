/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:11:21 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 23:42:15 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent(va_list args, const char *format, t_numbers *n)
{
	t_chars	*chars;
	t_flag	flags;
	int		form;

	form = 0;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 1, args, &form);
	chars->str[0] = '%';
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, 1, n);
	return (form + 1);
}

int		ft_character(va_list args, const char *format, t_numbers *n)
{
	t_chars	*chars;
	t_flag	flags;
	int		form;

	form = 0;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 1, args, &form);
	if (flags.length == 4)
		return (ft_wide_char(args, form, flags, n));
	else
		chars->str[0] = va_arg(args, int);
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, 1, n);
	return (form + 1);
}

int		ft_string(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		form;
	int		i;
	t_chars	*chars;

	form = 0;
	i = -1;
	flags = ft_flags(format, 2, args, &form);
	if (flags.length == 4)
		return(ft_wide_str(args, form, flags, n));
	else
	{
		chars = ft_chars_malloc();
		chars->str = va_arg(args, char*);
	}
	ft_flag_app(flags, chars);
	if (flags.precision > 0)
		while (++i < flags.precision)
			chars->tmp[i] = chars->str[i];
	else
		chars->tmp = chars->str;
	ft_str_to_buf(chars, 2, n);
	return (form + 1);
}
