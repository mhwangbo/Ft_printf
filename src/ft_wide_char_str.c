/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_char_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:10:05 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 18:37:55 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wide_char(char *buf, va_list args, int **j, const char *format)
{
	t_flag	flags;
	int		i;
	int		form;
	wchar_t	*wstr;
	t_chars	*chars;

	form = 0;
	i = -1;
	chars = ft_chars_malloc();
	flags = ft_flags(format, 2, args, &form);
	wstr = va_arg(args, wchar_t*);
	if (wstr == NULL)
		wstr =L"(null)";
	ft_strlen = 
