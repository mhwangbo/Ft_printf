/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:11:21 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/07 16:48:40 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_width(t_numbers *n, t_flag flags)
{
	while (flags.width-- > 1)
		n->return_i += (flags.zero == 1 ?
		write(n->fd, "0", 1) : write(n->fd, " ", 1));
}

int		ft_percent(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		form;
	char	percent;

	form = 0;
	flags = ft_flags(format, 4, args, &form);
	percent = '%';
	if (flags.minus)
	{
		n->return_i += write(n->fd, &percent, 1);
		ft_char_width(n, flags);
	}
	else
	{
		ft_char_width(n, flags);
		n->return_i += write(n->fd, &percent, 1);
	}
	return (form + 1);
}

int		ft_character(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		form;
	char	c;

	form = 0;
	flags = ft_flags(format, 1, args, &form);
	if (flags.length == 4)
		return (ft_wide_char(args, form, flags, n));
	c = va_arg(args, int);
	if (flags.minus)
	{
		n->return_i += write(n->fd, &c, 1);
		ft_char_width(n, flags);
	}
	else
	{
		ft_char_width(n, flags);
		n->return_i += write(n->fd, &c, 1);
	}
	return (form + 1);
}
