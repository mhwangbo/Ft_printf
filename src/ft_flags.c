/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:03:23 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 16:44:07 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flags_app_s(t_flag fl, t_chars *chars, int *f)
{
	if (fl.hash == 1 && fl.spec == 4)
	{
		if (fl.spec == 4 && fl.base == 16)
		{
			chars->front[*f] = '0';
			*f += 1;
			chars->front[*f] = 'x';
			*f += 1;
		}
		else if (fl.spec == 4)
		{
			chars->front[*f] = '0';
			*f += 1;
		}
	}
}

void		ft_flag_app(t_flag fl, t_chars *chars)
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
	if (fl.hash == 0)
		ft_hash_a(&fl, chars, &i, &sign);
	ft_precision_a(&fl, chars, &len);
	if ((fl.plus == 1 && fl.spec == 3) || (fl.hash == 1 && fl.spec == 4))
		ft_plus_a(fl, chars, &len);
	if ((fl.plus == 1 && fl.spec == 3) && chars->str[0] != '-' && fl.zero == 1)
		chars->front[f++] = '+';
	while (fl.width > len && fl.width > fl.precision)
		ft_width_a(&fl, chars, &b, &f);
	ft_flags_app_s(fl, chars, &f);
	if ((fl.plus == 1 && fl.spec == 3) && chars->str[0] != '-' && fl.zero == 0)
		chars->front[f++] = '+';
	else if (fl.space == 1 && fl.spec == 3 && sign == 0)
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
	while (!ft_strchr("spdiouxXcCSDOU%", format[*form]))
	{
		if ((i < 2) && (ft_strchr("#0-+ ", format[*form])))
			i = ft_flag(format[*form], &flags);
		else if ((i < 3) && (format[*form] >= '0' && format[*form] <= '9'))
			i = ft_width(format, &flags, args, &form);
		else if ((i < 4) && (format[*form] == '.'))
			i = ft_precision(format, &flags, args, &form);
		else if ((i < 5) && (ft_strchr("hljz", format[*form])))
			i = ft_length(format, &flags, &form);
		*form += 1;
	}
	if (ft_strchr("CSDOU", format[*form]))
		i = ft_length(format, &flags, &form);
	return (flags);
}
