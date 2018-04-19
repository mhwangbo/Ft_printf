/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:11:49 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/18 19:39:20 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexa(char *buf, va_list args, int *j, const char *format)
{
	char			*str;
	char			*front;
	char			*back;
	t_flag			flags;
	unsigned int	form;

	front = ft_memalloc(256);
	back = ft_memalloc(256);
	form = va_arg(args, unsigned int);
	str = ft_uitoa_base(form, 16);
	form = 0;
	flags = ft_flags(format, 6, args, (int*)&form);
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
