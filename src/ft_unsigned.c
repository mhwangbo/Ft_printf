/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:28:57 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/29 16:52:28 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
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
	if (flags.minus)
	{
		ft_un_hash(&flags, n);
		ft_un_put(str, n, flags);
		ft_d_width(n, flags, len);
	}
	else
	{
		if (flags.zero)
		{
			ft_un_hash(&flags, n);
			ft_d_width(n, flags, len);
			ft_un_put(str, n, flags);
		}
		else
		{
			ft_d_width(n, flags, len);
			ft_un_hash(&flags, n);
			ft_un_put(str, n, flags);
		}
	}
	free(str);
	return (form + 1);
} */

void	ft_un_width(t_numbers *n, t_flag flags, int len)
{
	if (flags.precision > len)
		while (flags.width-- > flags.precision)
			n->return_i += (flags.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
	else
		while (flags.width-- > len)
			n->return_i += (flags.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
}

void	ft_un_put(char *str, int len, t_numbers *n, t_flag flags)
{
	int		i;

	i = flags.precision;
	if (flags.zero)
		ft_d_width(n, flags, len);
	while (i-- > len)
		n->return_i += write(1, "0", 1);
	if (str[0] == '0' && flags.pre_e == 1 && flags.precision == 0)
		flags.width > 0 ? n->return_i += write(1, " ", 1) : 0;
	else
		ft_str_put(str, len, n);
	if (flags.minus)
		ft_d_width(n, flags, len);
}

void	ft_un_precision(t_flag *flags)
{
	if ((flags->plus || flags->space) && !flags->sign)
		flags->width -= 1;
	else if (flags->sign)
		flags->width -= 1;
	if (flags->minus)
		flags->zero = 0;
	if (flags->zero && flags->precision < flags->width && flags->pre_e)
		flags->zero = 0;
}


int		ft_unsigned(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	long long	i;
	int			len;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	i = ft_un_cv(flags, args);
	str = ft_itoa(i);
	len = ft_strlen(str);
	ft_un_precision(&flags);
	if (flags.minus || flags.zero)
		flags.sign == 1 ?
		ft_un_put(str + 1, len, n, flags) : ft_un_put(str, len, n, flags);
	else
	{
		ft_d_width(n, flags, len);
		flags.sign == 1 ?
		ft_un_put(str + 1, len, n, flags) : ft_un_put(str, len, n, flags);
	}
	free(str);
	return (form + 1);
}
