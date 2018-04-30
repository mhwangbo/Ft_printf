/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:28:57 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/29 20:07:07 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_s(const char *format, t_flag *flags)
{
	int		i;
	int		base;

	i = 0;
	base = 10;
	while (!(ft_strchr("oOuUxX", format[i])))
		i++;
	if (format[i] == 'o' || format[i] == 'O')
		base = 8;
	else if (format[i] == 'u' || format[i] == 'U')
		base = 10;
	else if (format[i] == 'x' || format[i] == 'X')
	{
		if (format[i] == 'X')
			flags->x = 1;
		base = 16;
	}
	return (base);
}

void	ft_un_write(char c, t_numbers *n, t_flag flags)
{
	char	a;

	a = c - 32;
	if (flags.x == 1 && (c >= 'a' && c <= 'z'))
		n->return_i += write(1, &a, 1);
	else
		n->return_i += write(1, &c, 1);
}

void	ft_un_put(char *str, t_numbers *n, t_flag flags)
{
	int		i;
	int		len;
	int		j;

	i = flags.precision;
	len = ft_strlen(str);
	while (i-- > len)
		n->return_i += write(1, "0", 1);
	if(str[0] == '0' && flags.pre_e == 1 && flags.precision == 0)
	   flags.width > 0 ? n->return_i += write(1, " ", 1) : 0;
	else
	{
		j = 0;
		while (str[j] == '0' && flags.o_zero == 0)
			j++;
		while (str[j])
			ft_un_write(str[j++], n, flags);
	}
}
void	ft_un_hash(t_flag *flags, t_numbers *n)
{
	if (flags->hash == 1)
	{
		if (flags->base == 8 || flags->base == 16)
			ft_un_write('0', n, *flags);
		if (flags->base == 16)
			ft_un_write('x', n, *flags);
	}
}
		
void	ft_unsigned_ss(unsigned long long i, t_flag *flags, char *str)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->zero && flags->precision < flags->width && flags->pre_e)
		flags->zero = 0;
	if (i == 0)
	{
		if (flags->pre_e == 1 && flags->precision == 0)
		{
			if (flags->base == 16)
				flags->hash = 0;
		}
		else
		{
			flags->o_zero = 1;
			flags->hash = 0;
			str[0] = '0';
		}
	}
	if (flags->hash == 1 && flags->pre_e == 1 && flags->precision == 0)
		return;
	else if (flags->hash == 1)
	{
		if (flags->base == 8)
			flags->width -= 1;
		else if (flags->base == 16)
			flags->width -= 2;
	}
}

int		ft_unsigned(va_list args, const char *format, t_numbers *n)
{
	t_flag				flags;
	int					form;
	unsigned long long	i;
	char				*str;
	int					len;

	form = 0;
	flags = ft_flags(format, 4, args, &form);
	flags.base = ft_unsigned_s(format, &flags);
	i = ft_un_cv(flags, args);
	str = ft_llitoa_base(i, flags.base);
	ft_unsigned_ss(i, &flags, str);
	len = ft_strlen(str);
//	if (flags.minus)
//	{
//		ft_un_hash(&flags, n);
//		ft_un_put(str, n, flags);
//		ft_d_width(n, flags, len);
//	}
//	else
//	{
//		if (flags.zero)
//		{
//			ft_un_hash(&flags, n);
//			ft_d_width(n, flags, len);
//			ft_un_put(str, n, flags);
//		}
//		else
//		{
//			ft_d_width(n, flags, len);
//			ft_un_hash(&flags, n);
//			ft_un_put(str, n, flags);
//		}
//	}
	free(str);
	return (form + 1);
}
/*
void	ft_to_capital(t_chars *chars, const char *format)
{
	int		i;

	i = 0;
	while (!ft_strchr("oOuUxX", format[i]))
		i++;
	if (format[i] == 'X')
	{
		i = -1;
		while (chars->str[++i])
		{
			if (chars->str[i] >= 'a' && chars->str[i] <= 'z')
				chars->str[i] -= 32;
		}
		i = -1;
		while (chars->front[++i])
			if (chars->front[i] >= 'a' && chars->front[i] <= 'z')
				chars->front[i] -= 32;
	}
}

int		ft_unsigned_s(const char *format)
{
	int		i;
	int		base;

	i = 0;
	base = 10;
	while (!(ft_strchr("oOuUxX", format[i])))
		i++;
	if (format[i] == 'o' || format[i] == 'O')
		base = 8;
	else if (format[i] == 'u' || format[i] == 'U')
		base = 10;
	else if (format[i] == 'x' || format[i] == 'X')
		base = 16;
	return (base);
}

int		ft_unsigned(va_list args, const char *format, t_numbers *n)
{
	t_flag				flags;
	int					form;
	t_chars				*chars;
	unsigned long long	i;

	form = 0;
	flags = ft_flags(format, 4, args, &form);
	chars = ft_chars_malloc();
	flags.base = ft_unsigned_s(format);
	i = ft_un_cv(flags, args);
	if (i == 0)
	{
		chars->str[0] = '0';
		flags.o_zero = 1;
		flags.hash = 0;
	}
	else
		chars->str = ft_llitoa_base(i, flags.base);
	ft_flag_app(flags, chars);
	ft_to_capital(chars, format);
	ft_str_to_buf(chars, n);
	free(chars);
	return (form + 1);
} */
