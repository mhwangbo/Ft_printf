/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_char_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:10:05 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 20:58:13 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(char c)
{
	write(1, &c, 1);
}

void	ft_putwc(wchar_t wc)
{
	if (wc <= 0x7F)
		ft_putwchar(wc);
	else if (wc <= 0x7FF)
	{
		ft_putwchar((wc >> 6) + 0xC0);
		ft_putwchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putwchar((wc >> 12) + 0xE0);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putwchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putwchar((wc >> 18) + 0xF0);
		ft_putwchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putwchar((wc & 0x3F) + 0x80);
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
	ft_putwc(wc);
	printf("a\n");
	if (chars->back)
		ft_putstr_t(chars->back, n);
	printf("b\n");
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
		ft_putwc(ws[i]);
	n->return_i = i - 1;
	if (chars->back)
		ft_putstr_t(chars->back, n);
	return (form + 1);
}
