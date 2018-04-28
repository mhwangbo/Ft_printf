/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:28:57 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/26 20:01:53 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_to_capital(t_chars *chars, const char *format)
{
	int		i;

	i = 0;
	while (!ft_strchr("oOuUxX", format[i]))
		i++;
	if (format[i] == 'X')
	{
		i = -1;
		while (chars->str[++i])
		{
			if (chars->str[i] >= 'a' && chars->str[i] <= 'z')
				chars->str[i] -= 32;
		}
		i = -1;
		while (chars->front[++i])
			if (chars->front[i] >= 'a' && chars->front[i] <= 'z')
				chars->front[i] -= 32;
	}
}

int		ft_unsigned_s(const char *format)
{
	int		i;
	int		base;

	i = 0;
	base = 10;
	while (!(ft_strchr("oOuUxX", format[i])))
		i++;
	if (format[i] == 'o' || format[i] == 'O')
		base = 8;
	else if (format[i] == 'u' || format[i] == 'U')
		base = 10;
	else if (format[i] == 'x' || format[i] == 'X')
		base = 16;
	return (base);
}

void	ft_unsigned_ss(t_flag *flags, t_chars *chars)
{
	if (flags->pre_e == 1 && flags->precision == 0)
		chars->str++;
	else
	{
		chars->str[0] = '0';
		flags->o_zero = 1;
		flags->hash = 0;
	}
}

int		ft_unsigned(va_list args, const char *format, t_numbers *n)
{
	t_flag				flags;
	int					form;
	t_chars				*chars;
	unsigned long long	i;

	form = 0;
	flags = ft_flags(format, 4, args, &form);
	chars = ft_chars_malloc();
	flags.base = ft_unsigned_s(format);
	i = ft_un_cv(flags, args);
	if (i == 0)
		ft_unsigned_ss(&flags, chars);
	else
		chars->str = ft_llitoa_base(i, flags.base);
	ft_flag_app(flags, chars);
	ft_to_capital(chars, format);
	ft_str_to_buf(chars, 4, n);
	ft_chars_free(chars, flags);
	return (form + 1);
}
