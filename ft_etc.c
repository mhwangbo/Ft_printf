/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:30:37 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/18 21:00:33 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_chars		*ft_chars_malloc(void)
{
	t_chars *chars;

	chars = ft_memalloc(sizeof(t_chars) * 1);
	chars->front = ft_memalloc(256);
	chars->back = ft_memalloc(256);
	chars->str = ft_memalloc(256);
	chars->tmp = ft_memalloc(256);
	return (chars);
}

void		ft_str_to_buf(char *str, char *buf, int **j)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		buf[**j] = str[i];
		**j += 1;
	}
}
