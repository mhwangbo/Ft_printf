/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:38:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/25 16:05:45 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_put(char *str, int len, t_numbers *n)
{
	int	i;

	i = -1;
	while (++i < len)
		n->return_i += write(1, &str[i], 1);
}

void	ft_str_width(t_numbers *n, t_flag flags, int len)
{
	while (flags.width-- > len)
		n->return_i += write(1, " ", 1);
}

int		ft_string(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		form;
	char	*str;
	int		len;

	form = 0;
	flags = ft_flags(format, 2, args, &form);
	if (flags.length == 4)
		return (ft_wide_str(args, form, flags, n));
	str = ft_strdup(va_arg(args, char*));
	len = ft_strlen(str);
	if (flags.precision < len && flags.pre_e == 1)
		len = flags.precision;
	if (flags.minus)
	{
		ft_str_put(str, len, n);
		ft_str_width(n, flags, len);
	}
	else
	{
		ft_str_width(n, flags, len);
		ft_str_put(str, len, n);
	}
	free(str);
	return (form + 1);
}
