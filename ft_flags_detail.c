/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_detail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:57:30 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/18 20:47:00 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_length(const char *format, t_flag *flags, int **form)
{
	return (4);
}

int		ft_precision(const char *format, t_flag *flags, va_list args, int **form)
{
	char	*precision;
	int		i;

	precision = ft_memalloc(256);
	i = 0;
	**form += 1;
	if (format[**form] == '*')
	{
		flags->precision = va_arg(args, int);
		return (3);
	}
	while (format[**form] >= '0' && format[**form] <= '9')
	{
		precision[i++] = format[**form];
		**form += 1;
	}
	flags->precision = ft_atoi(precision);
	free(precision);
	**form -= 1;
	return (3);
}

int		ft_width(const char *format, t_flag *flags, va_list args, int **form)
{
	char	*width;
	int		i;

	width = ft_memalloc(256);
	i = 0;
	if (format[**form] == '*')
	{
		flags->width = va_arg(args, int);
		return (2);
	}
	while (format[**form] >= '0' && format[**form] <= '9')
	{
		width[i++] = format[**form];
		**form += 1;
	}
	flags->width = ft_atoi(width);
	free(width);
	**form -= 1;
	return (2);
}

int		ft_flag(const char format, t_flag *flags)
{
	if (format == '-')
		flags->minus = 1;
	else if (format == '0')
		flags->zero = 1;
	else if (format == '+')
		flags->plus = 1;
	else if (format == ' ')
		flags->space = 1;
	else if (format == '#')
		flags->hash = 1;
	return (1);
}
