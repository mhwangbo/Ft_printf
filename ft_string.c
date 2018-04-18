/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:50:38 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 19:22:28 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_string(char *buf, va_list args, int *j, const char *format)
{
	char	*str;
	char	*front;
	char	*back;
	char	*tmp;
	t_flag	flags;
	int		form;
	int		i;

	form = 0;
	i = -1;
	front = ft_memalloc(256);
	back = ft_memalloc(256);
	tmp = ft_memalloc(256);
	flags = ft_flags(format, 2, args, &form);
	str = va_arg(args, char*);
	ft_flag_app(flags, front, back, str);
	if (flags.precision > 0)
	{
		while (++i < flags.precision)
			tmp[i] = str[i];
	}
	str = ft_strjoin(front, tmp);
	str = ft_strjoin(str, back);
	while (*str != '\0')
	{
		buf[*j] = *str;
		str++;
		*j += 1;
	}
	free(front);
	free(back);
	return (form);
}
