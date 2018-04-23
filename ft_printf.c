/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 14:42:11 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 0 = int converted to unsigned char
** 1 = char *
** 2 = signed decimal
** 3 = unsigned octal, unsigned decimal, unsigned hexadecimal (x & X)
*/

//int		(*g_diff_type[5])(char *buf, va_list args, int *j, const char
//		*format) = {ft_character, ft_string, ft_decimal, ft_unsigned,
//	ft_pointer};

int		ft_printf_send(char *buf, va_list args, t_numbers *n, const char *format)
{
	if (n->spec == 0)
		return (ft_character(buf, args, &n->j, format));
	else if (n->spec == 1)
		return (ft_string(buf, args, &n->j, format));
	else if (n->spec == 2)
		return (ft_decimal(buf, args, &n->j, format));
	else if (n->spec == 3)
		return (ft_unsigned(buf, args, &n->j, format));
	else if (n->spec == 4)
		return (ft_pointer(buf, args, &n->j, format));
	return (-1);
}

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
	else if (format[i] == 'p')
		return (4);
	return (-1);
}


int		ft_vsprintf(char *buf, const char *format, va_list args, t_numbers n)
{
	ft_bzero(&n, sizeof(t_numbers));
	while (format[n.i] != '\0')
	{
		if (format[n.i] == '%')
		{
			n.k = n.i++;
			while (!ft_strchr("sSpdDioOuUxXcC%", format[n.i]))
				n.i++;
			if (ft_strchr("sSpdDioOuUxXcC", format[n.i]))
			{
				n.spec = ft_vsprintf_s(format, n.i);
				format += n.k;
//				n.i = g_diff_type[n.spec](buf, args, &n.j, format);
				n.i = ft_printf_send(buf, args, &n, format);
				format += n.i;
				n.i = 0;
			}
			else if (format[n.i++] == '%')
				buf[n.j++] = '%';
		}
		if (format[n.i] != '%')
			buf[n.j++] = format[n.i++];
	}
	buf[n.j] = '\0';
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	char		*buf;
	int			k;
	t_numbers	n;

	k = -1;
	ft_bzero(&n, sizeof(t_numbers));
	buf = ft_memalloc(256);
	va_start(args, format);
	i = ft_vsprintf(buf, format, args, n);
	va_end(args);
	ft_putstr(buf);
	free(buf);
	return (i);
}
