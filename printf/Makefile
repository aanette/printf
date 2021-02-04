# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 14:06:07 by aanette           #+#    #+#              #
#    Updated: 2021/01/22 05:30:46 by aanette          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			ft_putchar.c \
			ft_strchr.c \
			ft_isdigit.c \
			ft_itoa.c \
			ft_strlen.c \
			ft_check.c \
			ft_width.c \
			ft_prinall.c \
			ft_widthneg.c \
			ft_uint.c \
			ft_width2.c \
			ft_itoa_base.c \
			ft_putstr.c \
			ft_makex.c \
			ft_printall.c \
			ft_printall2.c \
			ft_for_width.c \
			ft_nbrp_pr.c \
			ft_nbrp.c \
			ft_norma.c \
			ft_norm2.c \

OBJS		= $(SRCS:.c=.o)

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

