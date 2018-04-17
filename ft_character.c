/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:11:21 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 14:27:58 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_character(char *buf, va_list args, int *j, const char *format)
{
	char	*str;
	char	*front;
	char	*back;
	t_flag	flags;
	int		form;

	form = 0;
printf("ft_character: begining\n");
	front = ft_memalloc(256);
	back = ft_memalloc(256);
	str = ft_memalloc(256);
	flags = ft_flags(format, 1, args, &form);
printf("ft_character: after flag struct flag.width [%d]\n", flags.width);
	str[0] = va_arg(args, int);
	ft_flag_app(flags, front, back, str);
printf("ft_character: after flag application\n");
	str = ft_strjoin(front, str);
	str = ft_strjoin(str, back);
	while (*str != '\0')
	{
		buf[*j] = *str;
		str++;
		*j += 1;
printf("ft_character: j [%d]\n", *j);
	}
printf("ft_character: buf = %s\n", buf);
printf("ft_character: add str to buf\n");
	free(front);
	free(back);
//	free(str);
printf("ft_character: end\n");
return (form);
}
