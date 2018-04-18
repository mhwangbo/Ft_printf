/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:03:23 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 17:15:58 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_app(t_flag flags, char *front, char *back, char *str)
{
	int		b;
	int		f;
	int		i;
	int		len;
	int		sign;

	b = 0;
	f = 0;
	i = 0;
	sign = 0;
	if (flags.hash == 0 && (flags.spec >= 4 && flags.spec <= 6))
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = 1;
			str = ft_strdup(str + 1);
		}
		while (str[i] == '0')
			i++;
		str = ft_strdup(str + 3);
	}
	while (flags.width > ft_strlen(str))
	{
		if (flags.minus == 1)
		{
			back[b++] = ' ';
			printf("::::%s::::\n", back);
		}
		else
		{
			printf("____%s____\n", back);
			if (flags.zero == 1 && flags.spec > 2 && flags.precision == 0)
				front[f++] = '0';
			else
				front[f++] = ' ';
		}
		flags.width--;
	}
	if (flags.precision != 0 && flags.spec == 2)
		str[flags.precision] = '\0';
	if (flags.plus == 1 && flags.spec == 3)
	{
		if (sign == 1)
			front[f++] = '-';
		else
			front[f++] = '+';
	}
	else if (flags.space == 1 && flags.spec == 3)
		if (sign == 0)
			front[f++] = ' ';
	back[b] = '\0';
	front[f] = '\0';
}

t_flag		ft_flags(const char *format, int s, va_list args, int *form)
{
	t_flag	flags;
	int		i;

	ft_bzero(&flags, sizeof(t_flag));
	flags.spec = s;
	*form += 1;
	i = 0;
	while (!ft_strchr("sSpdDioOuUxXcC%", format[*form]))
	{
		if ((i < 2) && (ft_strchr("#0-+ ", format[*form])))
			i = ft_flag(format[*form], &flags);
		else if ((i < 3) && (format[*form] >= '0' && format[*form] <= '9'))
			i = ft_width(format, &flags, args, &form);
		else if ((i < 4) && (format[*form] == '.'))
			i = ft_precision(format, &flags, args, &form);
		else if ((i < 5) && (ft_strchr("hlLzjt", format[*form])))
			i = ft_length(format, &flags, &form);
		*form += 1;
	}
	printf("width [%d] minus [%d]\n", flags.width, flags.minus);
	return (flags);
}
