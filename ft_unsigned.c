/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:55:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/19 13:00:31 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_s(const char *format)
{
	int		i;
	int		base;

	i = -1;
	while (format[++i])
	{
		if (format[i] == 'o')
		{
			base = 8;
			break ;
		}
		else if (format[i] == 'u')
		{
			base = 10;
			break ;
		}
		else if (format[i] == 'x')
		{
			base = 16;
			break ;
		}
	}
	return (base);
}

int		ft_unsigned(char *buf, va_list args, int *j, const char *format)
{
	t_flag			flags;
	unsigned int	form;
	t_chars			*chars;
	int				base;

	chars = ft_chars_malloc();
	form = va_arg(args, unsigned int);
	base = ft_unsigned_s(format);
	chars->str = ft_uitoa_base(form, base);
	form = 0;
	flags = ft_flags(format, 4, args, (int*)&form);
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, buf, &j, 4);
	return (form + 1);
}
