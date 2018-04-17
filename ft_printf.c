/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 14:28:01 by mhwangbo         ###   ########.fr       */
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

	i = -1;
	j = 0;
printf("ft_vsprintf: beginning of ft_vsprintf\n");
printf("ft_vsprintf: i [%d]\n", i);
	while (format[++i] != '\0')
	{
printf("ft_vsprintf: format[%d] [ %c ]\n", i, format[i]);
printf("ft_vsprintf: begin format loop, ft_vsprintf\n");
		if (format[i] == '%')
		{
printf("ft_vsprintf: succesfully came to format[i] == '%%'\n");
			i++;
			k = i;
			while (!ft_strchr("sSpdDioOuUxXcC%", format[i]))
				i++;
printf("ft_vsprintf: string compared in ft_vsprintf success\n");
			if (format[i] == 'c' || format[i] == 'C')
			{
printf("ft_vsprintf: character, format[%d] = %c\n", i, format[i]);
				format += k;
printf("ft_vsprintf: format[%d] = %c  j [%d]\n", i, format[0], j);
				i = ft_character(buf, args, &j, format) + 1;
				format += j;
				i = 0;
printf("ft_vsprintf: after ft_character buf = %s  j [%d]\n", buf, j);
			}
	//			else if (format[i] == 's' || format[i] == 'S')
	//				ft_string(buf, args, &j, format);
	//			else if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i')
	//				ft_decimal(buf, args, &j, format);
	//			else if (format[i] == 'o' || format[i] == 'O')
	//				ft_octal(buf, args, &j, format);
	//			else if (format[i] == 'u' || format[i] == 'U')
	//				ft_unsigned_d(buf, args, &j, format);
	//			else if (format[i] == 'x' || format[i] == 'X')
	//				ft_hexa(buf, args, &j, format);
			else if (format[i] == '%')
			{
				buf[j++] = '%';
				format += 2;
			}
		}
		buf[j++] = format[i];
	}
printf("ft_vsprintf: out of while loop\n");
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	char		*buf;
	t_flag		flags;

	buf = ft_memalloc(256);
	va_start(args, format);
printf("ft_printf: va_start worked\n");
	i = ft_vsprintf(buf, format, args);
printf("ft_printf: ft_vsprintf worked\n");
	va_end(args);
printf("ft_printf: ft_va_end worked\n");
	ft_putstr(buf);
	free(buf);
	return (i);
}
