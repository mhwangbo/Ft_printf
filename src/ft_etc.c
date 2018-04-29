/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:30:37 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/28 20:58:28 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_chars_free(t_chars *chars)
{
	ft_strdel(&chars->front);
	ft_strdel(&chars->back);
	ft_strdel(&chars->str);
	ft_strdel(&chars->tmp);
	ft_memdel((void**)&chars);
}

t_chars		*ft_chars_malloc(void)
{
	t_chars *chars;

	chars = ft_memalloc(sizeof(t_chars) * 1);
	chars->front = ft_memalloc(256 * 4);
	chars->back = ft_memalloc(256 * 4);
	chars->str = ft_memalloc(256 * 4);
	chars->tmp = ft_memalloc(256 * 4);
	return (chars);
}

void		ft_putstr_t(char *s, t_numbers *n)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		n->return_i += write(1, &s[i++], 1);
}

void		ft_str_to_buf(t_chars *chars, t_numbers *n)
{
	chars->str = ft_strjoin(chars->front, chars->str);
	chars->str = ft_strjoin(chars->str, chars->back);
	ft_putstr_t(chars->str, n);
}
