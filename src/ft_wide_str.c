/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:10:54 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/01 17:35:26 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wstr_put(wchar_t *str, int len, t_numbers *n)
{
	int	i;

	i = -1;
	while (++i < len)
		n->return_i += write(n->fd, &str[i], 1);
}

int		ft_wstrlen(const wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

wchar_t	*ft_wstrdup(wchar_t *ws)
{
	wchar_t		*new;
	size_t		len;
	size_t		i;

	len = ft_wstrlen(ws);
	new = (wchar_t*)malloc(sizeof(wchar_t) * len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = ws[i];
	new[i] = '\0';
	return (new);
}

int		ft_wide_str(va_list args, int form, t_flag flags, t_numbers *n)
{
	int		len;
	wchar_t	*ws;

	ws = ft_wstrdup(va_arg(args, wchar_t*));
	len = ft_wstrlen(ws);
	if (flags.precision < len && flags.pre_e == 1)
		len = flags.precision;
	if (flags.minus)
	{
		ft_wstr_put(ws, len, n);
		ft_str_width(n, flags, len);
	}
	else
	{
		ft_str_width(n, flags, len);
		ft_wstr_put(ws, len, n);
	}
	free(ws);
	return (form + 1);
}
