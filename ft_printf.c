/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 19:22:47 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsprintf(char *buf, const char *format, va_list args)
{
	int		fo_len;
	int		i;
	int		j;
	int		k;
	char	*flag;

	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			k = i;
			i++;
			while (!ft_strchr("sSpdDioOuUxXcC%", format[i]))
				i++;
			if (format[i] == 'c' || format[i] == 'C')
			{
				format += k;
				i = ft_character(buf, args, &j, format) + 1;
				format += i;
				i = 0;
			}
			else if (format[i] == 's' || format[i] == 'S')
			{
				format += k;
				i = ft_string(buf, args, &j, format) + 1;
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
