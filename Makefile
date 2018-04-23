# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 14:47:29 by mhwangbo          #+#    #+#              #
#    Updated: 2018/04/23 15:04:35 by mhwangbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/

FILES = ft_printf.c\
		ft_char_str.c\
		ft_decimal.c\
		ft_etc.c\
		ft_flag_app_s.c\
		ft_flags.c\
		ft_flags_detail.c\
		ft_length.c\
		ft_pointer.c\
		ft_unsigned.c

LIBFILES = ft_itoa.c\
		   ft_memalloc.c\
		   ft_strjoin.c\
		   ft_strdup.c\
		   ft_strlen.c\
		   ft_bzero.c\
		   ft_strchr.c\
		   ft_atoi.c\
		   ft_uitoa_base.c\
		   ft_putstr.c

.PHONY = all clean fclean re

PRINTFSRCS = $(addprefix src/, $(FILES))
LIBSRCS = $(addprefix src/libft/, $(LIBFILES))

OBJ = $(PRINTFSRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBOBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(LIBOBJ) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBOBJ)

clean:
	@rm -rf $(OBJ) $(LIBOBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
