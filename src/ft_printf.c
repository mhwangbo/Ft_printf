/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/06 21:41:07 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 0 = int converted to unsigned char
** 1 = char *
** 2 = signed decimal
** 3 = unsigned octal (o), unsigned decimal (u),
** unsigned hexadecimal (x & X), unsigned binary (b)
** 4 = pointer
** 5 = percent
** 6 = change fd
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
	else if (n->spec == 6)
	{
		n->fd = va_arg(args, int);
		return (1);
	}
	else if (n->spec == 7)
		return (ft_non_print(args, format, n));
	else if (n->spec == 8)
		return (ft_floating_o(args, format, n));
	else if (n->spec == 9)
		return (ft_floating_hex(args, format, n));
	else if (n->spec == 10)
		return (ft_floating_e(args, format, n));
//	else if (n->spec == 11)
//		return (ft_n_save(args, format, n));
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
			format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
			format[i] == 'b')
		return (3);
	else if (format[i] == 'p')
		return (4);
	else if (format[i] == '%')
		return (5);
	else if (format[i] == 'w')
		return (6);
	else if (format[i] == 'r')
		return (7);
	else if (format[i] == 'f' || format[i] == 'F')
		return (8);
	else if (format[i] == 'a' || format[i] == 'A')
		return (9);
	else if (format[i] == 'e' || format[i] == 'E')
		return (10);
//	else if (format[i] == 'n')
//		return (11);
	return (-1);
}

void	ft_vsprintf_ss(const char *format, t_numbers *n)
{
	int	x;

	if (format[n->i] != '%' && format[n->i] != '\0')
	{
		ft_color(format + n->i, n, &x);
		if (x != 0)
		{
			n->i += 5;
		}
		else
		{
			n->return_i += write(n->fd, &format[n->i], 1);
			n->i += 1;
		}
	}
}

int		ft_vsprintf(const char *format, va_list args, t_numbers *n)
{
	ft_bzero(n, sizeof(t_numbers));
	n->fd = 1;
	while (format[n->i] != '\0')
	{
		if (format[n->i] == '%')
		{
			n->k = n->i++;
			while (!ft_strchr(FT_PREC, format[n->i]))
				n->i++;
			if (ft_strchr(FT_PREC, format[n->i]))
			{
				n->spec = ft_vsprintf_s(format, n->i);
				format += n->k;
				n->i = ft_printf_send(args, n, format);
				format += n->i;
				n->i = 0;
			}
		}
		ft_vsprintf_ss(format, n);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	t_numbers	n;

	ft_bzero(&n, sizeof(t_numbers));
	va_start(args, format);
	i = ft_vsprintf(format, args, &n);
	if (i == -1)
		return (-1);
	va_end(args);
	return (n.return_i);
}
