/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:27:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/06 20:37:51 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_n_save(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		*i;

	i = va_arg(args, int*);
	i = n->return_i;
	return (1);
}
