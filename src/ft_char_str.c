/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:11:21 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/25 14:51:54 by mhwangbo         ###   ########.fr       */
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
	flags = ft_flags(format, 4, args, &form);
	chars->str[0] = '%';
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, 1, n);
	ft_chars_free(chars, flags);
	return (form + 1);
}

int		ft_character(va_list args, const char *format, t_numbers *n)
{
	t_chars	*chars;
	t_flag	flags;
	int		form;

	form = 0;
	flags = ft_flags(format, 2, args, &form);
	if (flags.length == 4)
		return (ft_wide_char(args, form, flags, n));
	else
	{
		chars = ft_chars_malloc();
		chars->str[0] = va_arg(args, int);
	}
	if (chars->str[0] == '\0' && flags.width == 0)
		n->return_i += 1;
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, 1, n);
	ft_chars_free(chars, flags);
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
		return (ft_wide_str(args, form, flags, n));
	else
	{
		chars = ft_chars_malloc();
		chars->str = va_arg(args, char*);
	}
	ft_flag_app(flags, chars);
	if (flags.pre_e == 1)
		while (++i < flags.precision)
			chars->tmp[i] = chars->str[i];
	else
		chars->tmp = chars->str;
	ft_str_to_buf(chars, 2, n);
	ft_chars_free(chars, flags);
	return (form + 1);
}
