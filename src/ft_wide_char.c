/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_char_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:10:05 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 23:45:10 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(char c, t_numbers *n)
{
	n->return_i += write(1, &c, 1);
}

void	ft_putwc(wchar_t wc, t_numbers *n)
{
	if (wc <= 0x7F)
		ft_putwchar(wc, n);
	else if (wc <= 0x7FF)
	{
		ft_putwchar((wc >> 6) + 0xC0, n);
		ft_putwchar((wc & 0x3F) + 0x80, n);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putwchar((wc >> 12) + 0xE0, n);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80, n);
		ft_putwchar((wc & 0x3F) + 0x80, n);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putwchar((wc >> 18) + 0xF0, n);
		ft_putwchar(((wc >> 12) & 0x3F) + 0x80, n);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80, n);
		ft_putwchar((wc & 0x3F) + 0x80, n);
	}
}

int		ft_wide_char(va_list args, int form, t_flag flags, t_numbers *n)
{
	wchar_t	wc;
	t_chars	*chars;

	chars = ft_chars_malloc();
	wc = va_arg(args, wchar_t);
	ft_flag_app(flags, chars);
	if (chars->front)
		ft_putstr_t(chars->front, n);
	ft_putwc(wc, n);
	if (chars->back)
		ft_putstr_t(chars->back, n);
	ft_chars_free(chars, flags);
	return (form + 1);
}

int		ft_wide_str(va_list args, int form, t_flag flags, t_numbers *n)
{
	int		i;
	wchar_t	*ws;
	t_chars	*chars;

	chars = ft_chars_malloc();
	ws = va_arg(args, wchar_t*);
	i = -1;
	ft_flag_app(flags, chars);
	if (chars->front)
		ft_putstr_t(chars->front, n);
	while (ws[++i] != '\0')
		ft_putwc(ws[i], n);
	if (chars->back)
		ft_putstr_t(chars->back, n);
	ft_chars_free(chars, flags);
	return (form + 1);
}
