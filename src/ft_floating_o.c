/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:39:55 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/04 23:18:08 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_round_up(char **str)
{
	int		len;

	len = ft_strlen(str[0]);
	len--;
	(str[0][len] > '4') ? (str[0][len - 1] += 1) : 0;
	str[0][len] = '\0';
}

void	ft_ftoa_s(int *i, long double *val, int *n_val, char **tmp_t)
{
	*val *= 10;
	*n_val *= 10;
	tmp_t[0][*i] = ((int)*val - *n_val) + '0';
	*n_val = (int)*val;
	*i += 1;
}

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
		ft_ftoa_s(&i, &val, &n_val, &tmp_t);
	tmp_t[i] = 0;
	str = ft_strjoin(tmp, tmp_t);
	ft_round_up(&str);
	free(tmp);
	free(tmp_t);
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
	(flags.pre_e == 0) ? (flags.precision = 7) : (flags.precision += 1);
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
