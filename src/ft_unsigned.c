/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:28:57 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 15:04:29 by mhwangbo         ###   ########.fr       */
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
	}
}

int		ft_unsigned_s(const char *format)
{
	int		i;
	int		base;

	i = -1;
	base = 0;
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

int		ft_unsigned(char *buf, va_list args, int *j, const char *format)
{
	t_flag			flags;
	int				form;
	t_chars			*chars;
	int				base;
	unsigned		i;

	form = 0;
	flags = ft_flags(format, 4, args, &form);
	chars = ft_chars_malloc();
	i = ft_un_cv(flags, args);
	base = ft_unsigned_s(format);
	chars->str = ft_uitoa_base(i, base);
	ft_to_capital(chars, format);
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, buf, &j, 4);
	return (form + 1);
}
