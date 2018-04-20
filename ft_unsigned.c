/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:55:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/19 20:39:17 by mhwangbo         ###   ########.fr       */
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
	unsigned int	form;
	t_chars			*chars;
	int				base;

	chars = ft_chars_malloc();
	form = va_arg(args, unsigned int);
	base = ft_unsigned_s(format);
	chars->str = ft_uitoa_base(form, base);
	ft_to_capital(chars, format);
	form = 0;
	flags = ft_flags(format, 4, args, (int*)&form);
	ft_flag_app(flags, chars);
	ft_str_to_buf(chars, buf, &j, 4);
	return (form + 1);
}
