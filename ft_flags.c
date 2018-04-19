/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:03:23 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/19 14:04:15 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_app(t_flag flags, t_chars *chars)
{
	int		b;
	int		f;
	int		i;
	int		sign;
	int		len;

	b = 0;
	f = 0;
	i = 0;
	sign = 0;
	len = ft_strlen(chars->str);
	if (flags.hash == 0 && (flags.spec >= 4 && flags.spec <= 6))
	{
		if (chars->str[i] == '-' || chars->str[i] == '+')
		{
			if (chars->str[i] == '-')
				sign = 1;
			chars->str = ft_strdup(chars->str + 1);
		}
		while (chars->str[i] == '0')
			i++;
		chars->str = ft_strdup(chars->str + i);
	}
	if (flags.precision > 0 && flags.width > 0 && flags.spec == 2)
		len = flags.precision;
	if ((flags.plus == 1 && flags.spec == 3) ||
			(flags.hash == 1 && flags.spec == 4))
	{
		if (chars->str[0] != '-')
			len++;
		else if (flags.spec == 4)
			len++;
	}
	while (flags.width > len)
	{
		if (flags.minus == 1)
			chars->back[b++] = ' ';
		else
		{
			if (flags.zero == 1 && flags.spec > 2 && flags.precision == 0)
				chars->front[f++] = '0';
			else
				chars->front[f++] = ' ';
		}
		flags.width--;
	}
	if (flags.hash == 1)
	{
		if (flags.spec == 4)
			chars->front[f++] = '0';
	}
	if (flags.plus == 1 && flags.spec == 3)
	{
		if (chars->str[0] != '-')
			chars->front[f++] = '+';
	}
	else if (flags.space == 1 && flags.spec == 3)
		if (sign == 0)
			chars->front[f++] = ' ';
}

t_flag		ft_flags(const char *format, int s, va_list args, int *form)
{
	t_flag	flags;
	int		i;

	ft_bzero(&flags, sizeof(t_flag));
	flags.spec = s;
	*form += 1;
	i = 0;
	while (!ft_strchr("sSpdDioOuUxXcC%", format[*form]))
	{
		if ((i < 2) && (ft_strchr("#0-+ ", format[*form])))
			i = ft_flag(format[*form], &flags);
		else if ((i < 3) && (format[*form] >= '0' && format[*form] <= '9'))
			i = ft_width(format, &flags, args, &form);
		else if ((i < 4) && (format[*form] == '.'))
			i = ft_precision(format, &flags, args, &form);
		else if ((i < 5) && (ft_strchr("hlLzjt", format[*form])))
			i = ft_length(format, &flags, &form);
		*form += 1;
	}
	return (flags);
}
