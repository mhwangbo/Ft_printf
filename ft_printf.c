/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/19 15:11:13 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		(*g_diff_type[5])(char *buf, va_list args, int *j, const char
		*format) = {ft_character, ft_string, ft_decimal, ft_unsigned};

int		ft_vsprintf_s(const char *format, int i)
{
	if (format[i] == 'c' || format[i] == 'C')
		return (0);
	else if (format[i] == 's' || format[i] == 'S')
		return (1);
	else if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i')
		return (2);
	else if (format[i] == 'o' || format[i] == 'O' || format[i] == 'u' ||
			format[i] == 'U' || format[i] == 'x' || format[i] == 'X')
		return (3);
	return (-1);
}

int		ft_vsprintf(char *buf, const char *format, va_list args)
{
	int		i;
	int		j;
	int		k;
	int		spec;

	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			k = i++;
			while (!ft_strchr("sSpdDioOuUxXcC%", format[i]))
				i++;
			if (ft_strchr("sSpdDioOuUxXcC", format[i]))
			{
				spec = ft_vsprintf_s(format, i);
				format += k;
				i = g_diff_type[spec](buf, args, &j, format);
				format += i;
				i = 0;
			}
			else if (format[i++] == '%')
				buf[j++] = '%';
		}
		if (format[i] != '%')
			buf[j++] = format[i++];
	}
	buf[j] = '\0';
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	char		*buf;
	int			k;

	k = -1;
	buf = ft_memalloc(256);
	va_start(args, format);
	i = ft_vsprintf(buf, format, args);
	va_end(args);
	ft_putstr(buf);
	free(buf);
	return (i);
}
