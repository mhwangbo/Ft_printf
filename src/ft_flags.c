/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:03:23 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/28 20:28:59 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flags_app_s(t_flag fl, t_chars *chars, int *f)
{
	if (fl.hash == 1 && fl.spec == 4)
	{
		if (fl.spec == 4 && fl.base == 16 && fl.zero == 0)
		{
			if (fl.pre_e == 1 && fl.precision == 0)
				return ;
			chars->front[*f] = '0';
			*f += 1;
			chars->front[*f] = 'x';
			*f += 1;
		}
		else if (fl.spec == 4 && fl.base == 16 && fl.zero == 1)
		{
			if (fl.pre_e == 1 && fl.precision == 0)
				return ;
			chars->front[0] = '0';
			chars->front[1] = 'x';
		}
		else if (fl.spec == 4)
		{
			chars->front[*f] = '0';
			*f += 1;
		}
	}
}

void		ft_flag_app_ss(t_flag *fl, t_chars *chars, int *f)
{
	if ((fl->plus == 1 && fl->spec == 3) && fl->zero == 1)
	{
		chars->front[*f] = (fl->sign == 1 ? '-' : '+');
		*f += 1;
	}
	else if (fl->space == 1 && fl->spec == 3 && fl->zero == 1)
	{
		chars->front[*f] = (fl->sign == 1 ? '-' : ' ');
		*f += 1;
	}
	else if (fl->spec == 3 && fl->sign == 1 && fl->zero == 1)
	{
		chars->front[*f] = '-';
		*f += 1;
		fl->width--;
	}
}

void		ft_flag_app(t_flag fl, t_chars *chars)
{
	int		b;
	int		f;
	int		i;
	int		len;

	b = 0;
	f = 0;
	i = 0;
	len = ft_strlen(chars->str);
	if (fl.hash == 0)
		ft_hash_a(&fl, chars, &i);
	ft_precision_a(&fl, chars, &len);
	if ((fl.plus == 1 && fl.spec == 3) || (fl.hash == 1 && fl.spec == 4))
		ft_plus_a(&fl);
	ft_flag_app_ss(&fl, chars, &f);
	while (fl.width > len && fl.width > fl.precision)
		ft_width_a(&fl, chars, &b, &f);
	ft_flags_app_s(fl, chars, &f);
	if ((fl.plus == 1 && fl.spec == 3) && fl.zero == 0)
		chars->front[f++] = (fl.sign == 1 ? '-' : '+');
	else if (fl.spec == 3 && fl.zero == 0 && fl.sign == 1)
		chars->front[f++] = '-';
	else if (fl.space == 1 && fl.spec == 3 && fl.zero == 0 && fl.sign == 0)
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
		else if ((i < 3) && ((format[*form] >= '0' && format[*form] <= '9')
					|| (format[*form] == '*' && format[*form - 1] != '.')))
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
