/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:39:55 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/04 17:27:52 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(long double val, t_flag *flags)
{
	int		n_val;
	int		i;
	char	*tmp_t;
	char	*tmp;
	char	*str;

	i = 0;
	val < 0 ? (flags->sign = 1) : 0;
	val < 0 ? (val *= -1) : 0;
	n_val = (int)val;
	tmp = ft_itoa((flags->sign == 1 ? (n_val * -1) : n_val));
	tmp_t = ft_memalloc(256);
	tmp_t[i++] = '.';
	while (flags->precision--)
	{
		val *= 10;
		n_val *= 10;
		tmp_t[i++] = ((int)val - n_val) + '0';
		n_val = (int)val;
	}
	tmp_t[i] = 0;
	str = ft_strjoin(tmp, tmp_t);
	ft_round_up(str, flags);
	free(tmp);
	free(tmp_t);
	return (str);
}

char	*ft_round_up(char *str, t_flag *flags)
{
	int		len;
	int		i;

	i = 0;
	while (str[i] != '\0')
		str[i] == '.' ? break : i++;
	while (str[++i])
		len++;
	if (len > flags.precision && flags.pre_e == 1)
	{
		len--;
		while (len > flags.precision)
		{
			str[len] > 4 ? (str[len - 1] += 1) :  0;
			len--;
		}
	}
	return (str);
}


void	ft_f_width(t_numbers *n, t_flag flags, int len)
{
	while (flags.width-- > len)
		n->return_i += (flags.zero == 1 ?
		write(n->fd, "0", 1) : write(n->fd, " ", 1));
}

int		ft_floating_o(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	int			len;
	long double	i;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	flags.pre_e == 0 ? flags.precision = 6 : 0;
	i = ft_f_cv(flags, args);
	str = ft_ftoa(i, &flags);
	len = (flags.sign == 1 ? (ft_strlen(str) - 1) : ft_strlen(str));
	ft_d_precision(&flags);
	if (flags.minus || flags.zero)
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	else
	{
		ft_f_width(n, flags, len);
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	}
	free(str);
	return (form + 1);
}
