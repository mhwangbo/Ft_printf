/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 23:57:38 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 0 = int converted to unsigned char
** 1 = char *
** 2 = signed decimal
** 3 = unsigned octal, unsigned decimal, unsigned hexadecimal (x & X)
*/

int		ft_printf_send(va_list args, t_numbers *n, const char *format)
{
	if (n->spec == 0)
		return (ft_character(args, format, n));
	else if (n->spec == 1)
		return (ft_string(args, format, n));
	else if (n->spec == 2)
		return (ft_decimal(args, format, n));
	else if (n->spec == 3)
		return (ft_unsigned(args, format, n));
	else if (n->spec == 4)
		return (ft_pointer(args, format, n));
	else if (n->spec == 5)
		return (ft_percent(args, format, n));
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
	else if (format[i] == '%')
		return (5);
	return (-1);
}


int		ft_vsprintf(const char *format, va_list args, t_numbers *n)
{
	ft_bzero(n, sizeof(t_numbers));
	while (format[n->i] != '\0')
	{
		if (format[n->i] == '%')
		{
			n->k = n->i++;
			while (!ft_strchr("sSpdDioOuUxXcC%", format[n->i]))
				n->i++;
			if (ft_strchr("sSpdDioOuUxXcC%", format[n->i]))
			{
				n->spec = ft_vsprintf_s(format, n->i);
				format += n->k;
				n->i = ft_printf_send(args, n, format);
				format += n->i;
				n->i = 0;
			}
		}
			if (format[n->i] != '%' && format[n->i] != '\0')
			{
				n->return_i += write(1, &format[n->i], 1);
				n->i += 1;
			}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			k;
	t_numbers	n;

	k = -1;
	ft_bzero(&n, sizeof(t_numbers));
	va_start(args, format);
	i = ft_vsprintf(format, args, &n);
	va_end(args);
	return (n.return_i);
}
