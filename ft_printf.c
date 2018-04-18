/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 17:01:11 by mhwangbo         ###   ########.fr       */
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
				printf("ft_vsprintf: before: format = %s\n", format);
				i = ft_character(buf, args, &j, format) + 1;
				format += i;
				printf("ft_vsprintf: j [%d]\n", j);
				printf("ft_vsprintf: after: format = %s\n", format);
				i = 0;
			}
			else if (format[i] == '%')
			{
				buf[j++] = '%';
				format += 1;
				i++;
			}
		}
		if (format[i] != '%')
		{
			buf[j++] = format[i];
			i++;
		}

		printf("ft_vsprintf: buff = %s\n", buf);
	}
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
	printf("%s\n", buf);
	free(buf);
	return (i);
}
