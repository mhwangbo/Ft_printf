/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:39:55 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/30 20:21:19 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_floating_o(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	double		i;
	int			len;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	
