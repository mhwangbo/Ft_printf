/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:28:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/18 19:10:10 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_decimal(char *buf, va_list args, int *j, const char *format)
{
	char	*str;
	char	*front;
	char	*back;
	t_flag	flags;
	int		form;

	front = ft_memalloc(256);
	back = ft_memalloc(256);
	form = va_arg(args, int);
	str = ft_itoa(form);
	form = 0;
	flags = ft_flags(format, 3, args, &form);
	ft_flag_app(flags, front, back, str);
	str = ft_strjoin(front, str);
	str = ft_strjoin(str, back);
	while (*str != '\0')
	{
		buf[*j] = *str;
		str++;
		*j += 1;
	}
	free(front);
	free(back);
	return (form + 1);
}
