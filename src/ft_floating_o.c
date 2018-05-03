/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:39:55 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/02 20:09:42 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(double val, t_flag flags)
{
	int		n_val;
	int		i;
	char	*tmp_t;
	char	*tmp;
	char	*str;

	i = 0;
	val < 0 ? (flags.sign = 1) : 0;
	val < 0 ? (val *= -1) : 0;
	n_val = (int)val;
	tmp = ft_itoa((flags.sign == 1 ? (n_val * -1) : n_val));
	tmp_t = ft_memalloc(256);
	tmp_t[i++] = '.';
	while (flags.precision--)
	{
		val *= 10;
		n_val *= 10;
		tmp_t[i++] = ((int)val - n_val) + '0';
		n_val = (int)val;
	}
	tmp_t[i] = 0;
	str = ft_strjoin(tmp, tmp_t);
	free(tmp);
	free(tmp_t);
	return (str);
}

int		ft_floating_o(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	int			len;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	flags.pre_e == 0 ? flags.precision = 6 : 0;
	str = ft_ftoa(va_arg(args, double), flags);
	len = ft_strlen(str);

	return (form + 1);
}
