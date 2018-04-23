/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_app_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:30:17 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 15:01:12 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision_a(t_flag *flags, t_chars *chars, int *len)
{
	char	*front;
	int		i;

	front = ft_memalloc(256);
	if (flags->precision > 0 && flags->width > 0 && flags->spec == 2)
		*len = flags->precision;
	else if (flags->precision > *len && flags->spec > 2)
	{
		i = -1;
		while (++i < (flags->precision - *len))
			front[i] = '0';
		chars->str = ft_strjoin(front, chars->str);
	}
}

void		ft_hash_a(t_flag *flags, t_chars *chars, int *i, int *sign)
{
	if (flags->spec >= 4 && flags->spec <= 6)
	{
		if (chars->str[*i] == '-' || chars->str[*i] == '+')
		{
			if (chars->str[*i] == '-')
				*sign = 1;
			chars->str = ft_strdup(chars->str + 1);
		}
		while (chars->str[*i] == '0')
			*i += 1;
		chars->str = ft_strdup(chars->str + *i);
	}
	else if (flags->spec == 3 && flags->space == 1)
		flags->width -= 1;
}

void		ft_plus_a(t_flag flags, t_chars *chars, int *len)
{
	if (chars->str[0] != '-')
		*len += 1;
	else if (flags.spec == 4)
		*len += 1;
}

void		ft_width_a(t_flag *flags, t_chars *chars, int *b, int *f)
{
	if (flags->minus == 1)
	{
		chars->back[*b] = ' ';
		*b += 1;
	}
	else
	{
		if (flags->zero == 1 && flags->spec > 2 && flags->precision == 0)
			chars->front[*f] = '0';
		else
			chars->front[*f] = ' ';
		*f += 1;
	}
	flags->width -= 1;
}
