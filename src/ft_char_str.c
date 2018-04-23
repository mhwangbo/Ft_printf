/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:11:21 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 14:59:53 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_character(char *buf, va_list args, int *j, const char *format)
{
	t_chars	*chars;
	t_flag	flags;
	int		form;
	wchar_t	tmp;

	form = 0;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 1, args, &form);
	if (flags.length == 4)
	{
		tmp = va_arg(args, long);
		chars->str[0] = (char)tmp;
	}
	else
		chars->str[0] = va_arg(args, int);
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, buf, &j, 1);
	return (form + 1);
}

int		ft_string(char *buf, va_list args, int *j, const char *format)
{
	t_flag	flags;
	int		form;
	int		i;
	t_chars	*chars;
	wchar_t	*tmp;

	form = 0;
	i = -1;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 2, args, &form);
	if (flags.length == 4)
	{
		tmp = va_arg(args, wchar_t*);
		chars->str = (char*)tmp;
	}
	else
		chars->str = va_arg(args, char*);
	ft_flag_app(flags, chars);
	if (flags.precision > 0)
		while (++i < flags.precision)
			chars->tmp[i] = chars->str[i];
	else
		chars->tmp = chars->str;
	ft_str_to_buf(chars, buf, &j, 2);
	return (form + 1);
}