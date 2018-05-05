/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:17:53 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/03 00:29:37 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *s);
void			ft_bzero(void *s, size_t n);
int				ft_iswhite(const char s);
char			*ft_itoa(long long n);
char			*ft_itoa_base(long long n, int base);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *array, int constant_byte, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
size_t			ft_integerlen(long long n);
char			*ft_llitoa_base(unsigned long long n, int base);
size_t			ft_llintegerlen(unsigned long long n, int base);
void			ft_memdel(void **ap);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2,
		size_t n);

#endif
