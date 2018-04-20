/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_detail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:57:30 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/19 21:01:53 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_length(const char *format)
{
	int		i;

	i = 0;
	while (!ft_strchr("hljzCSDOU", format[i]))
		i++;
	if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
			return (0); //convert to char
		return (1); // convert to short
	}
	else if (format[i] == 'l' || format[i] == 'C' || format[i] == 'S' ||
			format[i] == 'D' || format[i] == 'O' || format[i] == 'U')
	{
		if (format[i + 1] == 'l')
			return (2); //convert to long long
		return (3); //convert to long
	}
	else if (format[i] == 'j')
		return (4); // convert to intmax_t
	else if (format[i] == 'z')
		return (5); // convert to size_t
	return (6);
}

int		ft_precision(const char *format, t_flag *flags, va_list args, int **f)
{
	char	*precision;
	int		i;

	precision = ft_memalloc(256);
	i = 0;
	**f += 1;
	if (format[**f] == '*')
	{
		flags->precision = va_arg(args, int);
		return (3);
	}
	while (format[**f] >= '0' && format[**f] <= '9')
	{
		precision[i++] = format[**f];
		**f += 1;
	}
	flags->precision = ft_atoi(precision);
	free(precision);
	**f -= 1;
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