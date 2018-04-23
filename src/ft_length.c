/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:10:14 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 16:12:12 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_d_cv(t_flag flags, va_list args)
{
	int		i;

	i = 0;
	if (flags.length == 0 || flags.length == 1 || flags.length == 2)
		i = va_arg(args, int);
	else if (flags.length == 3)
		i = (int)va_arg(args, long);
	else if (flags.length == 4)
		i = (int)va_arg(args, long long);
	else if (flags.length == 5)
		i = (int)va_arg(args, intmax_t);
	else if (flags.length == 6)
		i = (int)va_arg(args, size_t);
	return (i);
}

unsigned long long		ft_un_cv(t_flag flags, va_list args)
{
	if (flags.length == 0 || flags.length == 1 || flags.length == 2)
		return(va_arg(args, unsigned int));
	else if (flags.length == 3)
		return(va_arg(args, unsigned long));
	else if (flags.length == 4)
		return(va_arg(args, unsigned long long));
	else if (flags.length == 5)
		return(va_arg(args, intmax_t));
	else if (flags.length == 6)
		return(va_arg(args, size_t));
	return (0);
}
