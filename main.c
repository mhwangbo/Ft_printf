/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:41:28 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/17 19:22:10 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	printf("printf: abcd\n");
	ft_printf("ft_printf: abcd\n");
	printf("printf: [%c]\n", 'a');
	ft_printf("ft_printf: [%c]\n", 'a');
	printf("printf: [%-5.1s]\n", "zxcv");
	ft_printf("ft_printf: [%-5.1s]\n", "zxcv");
	printf("printf: [%-20c] [%-10.5s]\n", 'b', "qwertyuiopasdfghjkl");
	ft_printf("ft_printf: [%-20c] [%-10.5s]\n", 'b', "qwertyuiopasdfghjkl");
	
	return (0);
}
