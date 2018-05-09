/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:56:50 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/08 17:32:24 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_e_put(char *str, int len, t_numbers *n, t_flag flags)
{
	int		i;

	i = flags.precision;
	if (flags.sign)
		n->return_i += write(n->fd, "-", 1);
	else if (flags.plus && !flags.sign)
		n->return_i += write(n->fd, "+", 1);
	else if (flags.space && !flags.sign)
		n->return_i += write(n->fd, " ", 1);
	if (flags.zero)
		ft_d_width(n, flags, len);
	while (i-- > len)
		n->return_i += write(n->fd, "0", 1);
	if (str[0] == '0' && flags.pre_e == 1 && flags.precision == 0)
		flags.width > 0 ? n->return_i += write(n->fd, " ", 1) : 0;
	else
		ft_str_put(str, len, n);
	if (flags.minus)
		ft_d_width(n, flags, len);
}

void	ft_e_order(t_flag flags, char *str, int len, t_numbers *n)
{
	if (flags.minus || flags.zero)
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	else
	{
		ft_f_width(n, flags, len);
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	}
}

void	ft_ftoa_e_ss(long double *val, t_numbers *n)
{
	unsigned long long int	tmp;

	tmp = (unsigned long long int)*val;
	if (*val == 0)
		return ;
	else if (tmp > 9)
	{
		while (tmp > 9)
		{
			*val /= 10;
			tmp = (unsigned long long int)*val;
			n->e_no += 1;
		}
	}
	else if (tmp < 1)
	{
		while (tmp < 1)
		{
			*val *= 10;
			tmp = (unsigned long long int)*val;
			n->e_no -= 1;
		}
	}
}

void	ft_ftoa_e_s(int *i, long double *val, int *n_val, char **tmp_t)
{
	*val *= 10;
	*n_val *= 10;
	tmp_t[0][*i] = ((int)*val - *n_val) + '0';
	*n_val = (int)*val;
	*i += 1;
}

char	*ft_ftoa_e(long double val, t_flag *flags, t_numbers *n)
{
	long int	n_val;
	int			i;
	char		*tmp_t;
	char		*tmp;
	char		*str;

	i = 0;
	val < 0 ? (flags->sign = 1) : 0;
	val < 0 ? (val *= -1) : 0;
	ft_ftoa_e_ss(&val, n);
	n_val = (long int)val;
	tmp = ft_itoa((flags->sign == 1 ? (n_val * -1) : n_val));
	tmp_t = ft_memalloc(256);
	tmp_t[i++] = '.';
	while (flags->precision--)
		ft_ftoa_s(&i, &val, &n_val, &tmp_t);
	tmp_t[i] = 0;
	str = ft_strjoin(tmp, tmp_t);
	ft_round_up(&str);
	free(tmp);
	free(tmp_t);
	return (str);
}

void	ft_e_no_put(char **str, t_numbers *n, char type)
{
	char	*tmp;
	char	pre[3];
	char	*save;
	int		len;

	pre[0] = type;
	pre[2] = 0;
	n->e_no < 0 ? (pre[1] = '-') : (pre[1] = '+');
	n->e_no < 0 ? (n->e_no *= -1) : 0;
	len = ft_integerlen(n->e_no);
	(len == 1) ? (len += 1) : 0;
	tmp = (char*)ft_memalloc(sizeof(char) * (len + 1));
	tmp[len] = 0;
	while (0 < len)
	{
		tmp[--len] = (n->e_no % 10) + '0';
		n->e_no = n->e_no / 10;
	}
	(len == 1) ? (tmp[0] = '0') : 0;
	save = ft_strjoin(pre, tmp);
	free(tmp);
	tmp = str[0];
	str[0] = ft_strjoin(tmp, save);
	free(save);
	free(tmp);
}

int		ft_floating_e(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	int			len; 
	long double	i;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	if (format[form] == 'g' || format[form] == 'G')
		flags.spec = 10;
	(flags.pre_e == 0) ? (flags.precision = 7) : (flags.precision += 1);
	(flags.spec == 10) ? (flags.precision -= 1) : 0;
	i = ft_f_cv(flags, args);
	str = ft_ftoa_e(i, &flags, n);
	if (format[form] == 'g' || format[form] == 'G')
		ft_e_no_put(&str, n, format[form] - 2);
	else
		ft_e_no_put(&str, n, format[form]);
	len = (flags.sign == 1 ? (ft_strlen(str) - 1) : ft_strlen(str));
	ft_d_precision(&flags);
	ft_e_order(flags, str, len, n);
	free(str);
	return (form + 1);
}
